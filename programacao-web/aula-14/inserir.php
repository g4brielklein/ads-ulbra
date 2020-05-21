<?php
if(count($_POST)>0) {
	require_once("db.php");
		
	$sql = "INSERT INTO tbCategorias (catCodigo) VALUES ('" . $_POST["catCodigo"]')";
	mysqli_query($conect,$sql);
	$current_id = mysqli_insert_id($conect);
	if(!empty($current_id)) {
		$message = "Nova categoria incluída";
		header("Location:index.php");
	}
	else {
		// $message = "Erro na inclusão. Verifique o CGU escolhido!";
	}
	echo $message;
}
?>
	
