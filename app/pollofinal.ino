#include <ESP32Servo.h>
#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <SPI.h>
#include <Wire.h>

const char* ssid = "BUAP_Estudiantes";
const char* password = "f85ac21de4";

const char *mqtt_server = "broker.emqx.io";     //]
const int mqtt_port = 1883;                     //]
const char *mqtt_user = "pmxomwei";             //] Agregamos las credenciales de nuestro servidor
const char *mqtt_pass = "GguSEks38fre";         //] al que haremos la conexion 

WiFiClient espClien;
PubSubClient client(espClien); //declaramos una instancia de la lireria MQTT

int pos;

char var1;

Servo head;
Servo rightWing;
Servo leftWing;
Servo rightLeg;
Servo leftLeg;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int headPos = 0;
int rightWingPos = 0;
int leftWingPos = 0;
int rightLegPos = 0;
int leftLegPos = 0; 

void callback(char* topic, byte* payload, unsigned int length)
{
  Serial.print("Mensaje recibido bajo el topico -> ");
  Serial.print(topic);
  Serial.print(" ");
  for(int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }

  var1 = (char)payload[0];
  Serial.println();
}

void setup() {
      delay(500);
  //setup_wifi();
  WiFi.begin(ssid,password);

  Serial.begin(115200);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Conexión Exitosa");
  
  Serial.println("Mi ip es -> ");
  Serial.println(WiFi.localIP());

  client.setServer(mqtt_server,mqtt_port);
  client.setCallback(callback);

    head.attach(15);
    rightWing.attach(5);
    leftWing.attach(4);
    rightLeg.attach(2);
    leftLeg.attach(18);  // attaches the servo on pin 9 to the servo object
}

void reconnect(){
  while (!client.connected()){
    Serial.println("Intentando conexión MQTT");

    String clientId = "iot_1_";
    clientId = clientId + String(random(0xffff),HEX);

    if(client.connect(clientId.c_str(),mqtt_user,mqtt_pass)){
      Serial.println("Conexion a MQTT exitosa.!");
      client.publish("SalidaProyecto","Hola a todos");
      client.subscribe("entradaProyecto");
    }
    else{
      Serial.println("Fallo la conexion ");
      Serial.println(client.state());
      Serial.print("Se intentará de nuevo en 5 segundos");
      delay(5000);
    }
  }
}

void loop() {
  if(client.connected()==false){
    reconnect();
  }
  unsigned long tiempoActual = millis();
  
  client.loop();

  if (var1 == 'a')
  {
    rightWing.write(0);

    for (pos = 0; pos <= 30; pos += 1) {
    leftWing.write(pos);            
    delay(7);                       
    }
    for (pos = 30; pos >= 1; pos -= 1) {
    leftWing.write(pos);            
    delay(7);                       
    }
    for (pos = 1; pos <= 30; pos += 1) {
    leftWing.write(pos);            
    delay(7);                       
    }
    for (pos = 30; pos >= 1; pos -= 1) {
    leftWing.write(pos);            
    delay(7);                       
    }
    for (pos = 1; pos <= 30; pos += 1) {
    leftWing.write(pos);            
    delay(7);                       
    }
    for (pos = 30; pos >= 1; pos -= 1) {
    leftWing.write(pos);            
    delay(7);                       
    }
    for (pos = 1; pos <= 30; pos += 1) {
    leftWing.write(pos);            
    delay(7);                       
    }
    for (pos = 30; pos <= 100; pos += 1) {
    leftWing.write(pos);            
    delay(7);                       
    }

    var1 = 'x';

  }
  else if (var1=='b')
 {
   for (pos = 0; pos <= 100; pos += 1) {
    leftWing.write(pos);      
    rightWing.write(pos); 
    delay(7);
    }
    for (pos = 100; pos >= 0; pos -= 1) {
    leftWing.write(pos);      
    rightWing.write(pos); 
    delay(7);
    }
    for (pos = 0; pos <= 100; pos += 1) {
    leftWing.write(pos);      
    rightWing.write(pos); 
    delay(7);
    }
    for (pos = 100; pos >= 0; pos -= 1) {
    leftWing.write(pos);      
    rightWing.write(pos); 
    delay(7);
    }
    for (pos = 0; pos <= 100; pos += 1) {
    leftWing.write(pos);      
    rightWing.write(pos); 
    delay(7);
    }
    for (pos = 100; pos >= 0; pos -= 1) {
    leftWing.write(pos);      
    rightWing.write(pos); 
    delay(7);
    }
    for (pos = 0; pos <= 100; pos += 1) {
    leftWing.write(pos);      
    rightWing.write(pos); 
    delay(7);
    }
    for (pos = 100; pos >= 0; pos -= 1) {
    leftWing.write(pos);      
    rightWing.write(pos); 
    delay(7);
    }
    for (pos = 0; pos <= 100; pos += 1) {
    leftWing.write(pos);      
    rightWing.write(pos); 
    delay(7);
    }
    for (pos = 100; pos >= 0; pos -= 1) {
    leftWing.write(pos);      
    rightWing.write(pos); 
    delay(7);
    }
    for (pos = 0; pos <= 100; pos += 1) {
    leftWing.write(pos);      
    rightWing.write(pos); 
    delay(7);
    }
    for (pos = 100; pos >= 0; pos -= 1) {
    leftWing.write(pos);      
    rightWing.write(pos); 
    delay(7);
    }
    var1 = 'x';
  }
 else if (var1=='c')
 {
   for (pos = 0; pos <= 100; pos += 1) {
    leftWing.write(pos);      
    rightWing.write(100-pos); 
    delay(7);
    }
    for (pos = 100; pos >= 0; pos -= 1) {
    leftWing.write(pos);      
    rightWing.write(100-pos); 
    delay(7);
    }
    for (pos = 0; pos <= 100; pos += 1) {
    leftWing.write(pos);      
    rightWing.write(100-pos); 
    delay(7);
    }
    for (pos = 100; pos >= 0; pos -= 1) {
    leftWing.write(pos);      
    rightWing.write(100-pos); 
    delay(7);
    }
    for (pos = 0; pos <= 100; pos += 1) {
    leftWing.write(pos);      
    rightWing.write(100-pos); 
    delay(7);
    }
    for (pos = 100; pos >= 0; pos -= 1) {
    leftWing.write(pos);      
    rightWing.write(100-pos); 
    delay(7);
    }
    for (pos = 0; pos <= 100; pos += 1) {
    leftWing.write(pos);      
    rightWing.write(100-pos); 
    delay(7);
    }
    for (pos = 100; pos >= 0; pos -= 1) {
    leftWing.write(pos);      
    rightWing.write(100-pos); 
    delay(7);
    }
    for (pos = 0; pos <= 100; pos += 1) {
    leftWing.write(pos);      
    rightWing.write(100-pos); 
    delay(7);
    }
    for (pos = 100; pos >= 0; pos -= 1) {
    leftWing.write(pos);      
    rightWing.write(100-pos); 
    delay(7);
    }
    for (pos = 0; pos <= 100; pos += 1) {
    leftWing.write(pos);      
    rightWing.write(100-pos); 
    delay(7);
    }
    for (pos = 100; pos >= 0; pos -= 1) {
    leftWing.write(pos);      
    rightWing.write(100-pos); 
    delay(7);
    }
    var1 = 'x';

 }
 else if (var1=='d')
 {
   for (pos = 0; pos <= 100; pos += 1) {
    leftLeg.write(pos);      
    rightLeg.write(pos); 
    delay(7);
    }
    for (pos = 100; pos >= 0; pos -= 1) {
    leftLeg.write(pos);      
    rightLeg.write(pos); 
    delay(7);
    }
    for (pos = 0; pos <= 100; pos += 1) {
    leftLeg.write(pos);      
    rightLeg.write(pos); 
    delay(7);
    }
    for (pos = 100; pos >= 0; pos -= 1) {
    leftLeg.write(pos);      
    rightLeg.write(pos); 
    delay(7);
    }

for (pos = 0; pos <= 100; pos += 1) {
    leftLeg.write(pos);      
    rightLeg.write(pos); 
    delay(7);
    }
    for (pos = 100; pos >= 0; pos -= 1) {
    leftLeg.write(pos);      
    rightLeg.write(pos); 
    delay(7);
    }

for (pos = 0; pos <= 100; pos += 1) {
    leftLeg.write(pos);      
    rightLeg.write(pos); 
    delay(7);
    }
    for (pos = 100; pos >= 0; pos -= 1) {
    leftLeg.write(pos);      
    rightLeg.write(pos); 
    delay(7);
    }

for (pos = 0; pos <= 100; pos += 1) {
    leftLeg.write(pos);      
    rightLeg.write(pos); 
    delay(7);
    }
    for (pos = 100; pos >= 0; pos -= 1) {
    leftLeg.write(pos);      
    rightLeg.write(pos); 
    delay(7);
    }

for (pos = 0; pos <= 100; pos += 1) {
    leftLeg.write(pos);      
    rightLeg.write(pos); 
    delay(7);
    }
    for (pos = 100; pos >= 0; pos -= 1) {
    leftLeg.write(pos);      
    rightLeg.write(pos); 
    delay(7);
    }

for (pos = 0; pos <= 100; pos += 1) {
    leftLeg.write(pos);      
    rightLeg.write(pos); 
    delay(7);
    }
    for (pos = 100; pos >= 0; pos -= 1) {
    leftLeg.write(pos);      
    rightLeg.write(pos); 
    delay(7);
    }

for (pos = 0; pos <= 100; pos += 1) {
    leftLeg.write(pos);      
    rightLeg.write(pos); 
    delay(7);
    }
    for (pos = 100; pos >= 0; pos -= 1) {
    leftLeg.write(pos);      
    rightLeg.write(pos); 
    delay(7);
    }
var1 = 'x';

 }


  delay(7);
  
  /*
  for (pos = 0; pos <= 70; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(7);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 70; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(7);                       // waits 15ms for the servo to reach the position
  }
  */
}