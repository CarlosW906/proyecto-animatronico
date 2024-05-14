<?php
$conexion = mysqli_connect( "localhost","root","","Animatronico") or die("error en la conexion");

$usuario=$_POST['usuario'];
$contrasena=$_POST['contrasena'];
session_start();

$_SESSION['usuario']=$usuario;

$consulta="select *from registro where usuario='$usuario' and contrasena='$contrasena'";

$resultado=mysqli_query($conexion,$consulta);

$filas=mysqli_num_rows($resultado);

if($filas){
header("Location: inicio.html" );
}else{


	 echo '<script type="text/javascript">
        alert("las contrasenas no coinciden.");
      </script>';

}
 header("Location: login.html");
?>
