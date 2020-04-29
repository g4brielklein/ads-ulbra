<?php
if(count($_POST)>0) {
	require_once("db.php");
		
	$sql = "INSERT INTO Aluno (Nome, cgu) VALUES ('" . $_POST["Nome"] . "','" . $_POST["cgu"] ."')";
	mysqli_query($conect,$sql);
	$current_id = mysqli_insert_id($conect);
	if(!empty($current_id)) {
		$message = "Novo Aluno incluído";
		header("Location:inicio.php");
	}
	else {
		$message = "Erro na inclusão. Verifique o CGU escolhido!";
	}
	echo $message;
}
?>
	
