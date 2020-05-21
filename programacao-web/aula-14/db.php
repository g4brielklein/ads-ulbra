<?php
	$servidor = "localhost";
	$user = "root";
	$senha = "";
	$banco = "AdmVendas";
		
	$conect = mysqli_connect($servidor,$user,$senha);
	$db = mysqli_select_db($conect, $banco);
	$link = mysqli_connect($servidor, $user, $senha, $banco);
?>