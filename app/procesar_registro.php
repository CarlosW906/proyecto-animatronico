<?php

$conexion = new mysqli("localhost", "root", "", "animatronicobd");

if ($conexion->connect_error) {
    die("Error en la conexión: " . $conexion->connect_error);
}

$usuario = $_POST['usuario'];
$correo = $_POST['correo'];
$contrasena = $_POST['contrasena'];
$confirmar_contrasena = $_POST['confirmar_contrasena'];

// Validar que las contraseñas coincidan y tengan una longitud mínima
if ($contrasena !== $confirmar_contrasena) {
    echo "<script>alert('Las contraseñas no coinciden.'); window.location.href = 'registro.html';</script>";
    exit();
}

if (strlen($contrasena) < 8) {
    echo "<script>alert('La contraseña debe tener al menos 8 caracteres.'); window.location.href = 'registro.html';</script>";
    exit();
}

// Cifrar la contraseña antes de almacenarla
$contrasena_hash = password_hash($contrasena, PASSWORD_BCRYPT);

// Usar consultas preparadas para prevenir inyección SQL
$stmt = $conexion->prepare("INSERT INTO registro (usuario, correo, contrasena) VALUES (?, ?, ?)");
$stmt->bind_param("sss", $usuario, $correo, $contrasena_hash);

if ($stmt->execute()) {
    header("Location: inicio.html");
    exit();
} else {
    echo "Hubo un error al registrar el usuario: " . $stmt->error;
}

$stmt->close();
$conexion->close();

?>
