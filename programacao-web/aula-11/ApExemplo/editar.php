<!-- Página para editar dados do banco -->

<a href="editar.php?cgu=<?php echo $row["cgu"]; ?>" class="link">

<?php
    require_once("db.php");

    $query_select = "SELECT * FROM aluno WHERE cgu = ".$_GET["cgu"];
    $select = mysql_query($conect, $query_select);
?>

<html>
    <head>
        <title>Alterar dados de alunos</title>
        <link rel="stylesheet" type="text/css" href="styles.css">
    </head>
    <body>
        
    </body>
</html>