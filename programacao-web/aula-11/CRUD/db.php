<!-- Arquivo de configuração ou inclusão -->
<?php
    // Define as variáveis que serão utilizadas
    $servidor = 'localhost';
    $user = 'root';
    $senha = '';
    $banco = 'ulbra';
    // Define a conexão com o banco de dados
    $conect = mysqli_connect($servidor, $user, $senha);
    $db = mysqli_connect($servidor, $user, $senha, $banco);
?>
<!-- Para incluir em outras páginas, utilize: 
require_once('db.php');
-->