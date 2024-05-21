<?php
// Conexión a la base de datos
$conexion = new mysqli("localhost", "root", "", "animatronicobd");

if ($conexion->connect_error) {
    die("Error en la conexión: " . $conexion->connect_error);
}

// Recibir datos del formulario
$usuario = $_POST['usuario'];
$contrasena = $_POST['contrasena'];
session_start();

// Consulta segura utilizando consultas preparadas
$stmt = $conexion->prepare("SELECT * FROM registro WHERE usuario = ? AND contrasena = ?");
$stmt->bind_param("ss", $usuario, $contrasena);
$stmt->execute();
$resultado = $stmt->get_result();

// Verificar si hay una fila que coincide
if ($resultado) {
    $_SESSION['usuario'] = $usuario;
    header("Location: inicio.html");
    exit();
} else {
    echo '<script type="text/javascript">
            alert("Las contraseñas no coinciden.");
            window.location.href = "login.html";
          </script>';
}

$stmt->close();
$conexion->close();
?>
