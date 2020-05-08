<!-- Submete via POST para a página com código SQL de inclusão das informações -->

<html>
    <head>
        <title>Lista de Alunos</title>
        <link rel="stylesheet" type="text.css" href="styles.css" />
    </head>

    <!-- A página ao ser submetida envia os dados para inserir.php -->

    <form name="frmUser" method="POST" action="inserir.php">
        <div style="width: 500px;">

        <div align="right" style="padding-bottom: 5px;">
        <a href="1index.php" class="link">
        <img alt="List" title="List" src="images/casa.png" width="15px" height="15px"/>Alunos</a></div>

        <table border="0" cellpadding="10" cellspacing="0" width="500" align="center"
        class="tblSaveForm">
            <tr class="tableheader">
                <td colspan="2">Adicionar</td>
            </tr>

            <tr>
                <td><label>Nome</label></td>
                <td><input type=="text" name="nome" class="txtField"></td>
            </tr>


            <tr>
                <td><label>CGU</label></td>
                <td><input type="text" name="cgu" class="txtField"></td>
            </tr>
            <td colspan="2"><input type="submit" name="submit" value="incluir" onclick="return Confirmainc()" class="btnSubmit"></td>
            </tr>
        <table>
        
        </div>
    </form>
        </div>
        </body>
        </div>
</html>

<!-- Os dados são enviados via POST para a página inserir.php -->
<?php
    if (count($_POST)>0) { // Verifica se o vetor de parâmetros está com dados
        require_once("db.php"); // Adiciona a conexão e variáveis de banco
        $sql = "INSERT INTO aluno (nome, cgu)VALUES ('" . $_POST["nome"] . "','" . $_POST["cgu"] ."')";
        mysqli_query($conect,$sql); // Executa a query
        $current_id = mysqli_insert_id($conect); // Busca o id incluído

        // Verifica se ocorreu a nova inclusão
        if (!empty($current_id)) {
            $message = "Novo aluno incluído";
            header("Location:1index.php"); // Volta para a página inicial
        } else {
            $message = "Erro na inclusão. Verifique o CGU escolhido!";
        }
        echo $message;
    }
?>