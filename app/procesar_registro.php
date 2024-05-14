<?php

$conexion = mysqli_connect( "localhost","root","","Animatronico") or die("error en la conexion");

$bd = mysqli_select_db($conexion,"Animatronico") or die ("Error conexion al conectarse a la base de datos");

$usuario =$_POST['usuario'];
$correo=$_POST['correo'];
$contrasena=$_POST['contrasena'];
$confirmar_contrasena=$_POST['confirmar_contrasena'];

if($contrasena==$confirmar_contrasena){

$sql="INSERT INTO registro VALUES ('$usuario','$correo','$contrasena','$confirmar_contrasena')";

}else{


  echo "las contrasenas no coinciden.! ";

header("Location: registro.html" );
}

$ejecutar=mysqli_query($conexion, $sql);

if(!$ejecutar){
echo"Hubo un error";

}else{
  header("Location: inicio.html" );

}


?>