<!-- Página inicial da aplicação -->

<!-- Confirma a exclusão de um registro -->
<script>
    function Confirmadel() {
        var del = confirm('Você confirma a exclusão?')
        if (del == true) {
            alert('Registro excluído!')
        }
        return del;
    }
</script>

<!-- Lê as informações para a página -->
<?php
    require_once('db.php');

    $query_select = 'SELECT * FROM aluno';
    $select = mysqli_query($conect, $query_select);  
?>

<html>
    <head>
        <title>Lista de Alunos</title>
        <link rel='stylesheet' type='text/css' href='styles.css' />
    </head>
    <body>
        <form name='frmUser' method='post' action=''>
            <div style='width: 500px;'>
            <div align='right' style='padding-bottom: 5px;'>
            <a href='adicionar.php' class='link'>
            <img alt='Add' title='Add' src='images/add.png' width='15px' height='15px' />Incluir</a></div>
                <table border='0' cellpadding='10' cellspacing='1' width='500' class='tbListForm'>
                <tr class='listheader'>
                    <td>Nome</td>
                    <td>CGU</td>
                    <td width='20%'>Opções</td>
                </tr>
                <?php
                    $i = 0;
                    while ($row = mysqli_fetch_array($select)) {
                        if ($i % 2 == 0)
                            $classname = 'evenRow';
                        else
                            $classname = 'OddRow';
                ?>

                <tr class='<?php if(isset($classname))echo $classname;?>'>
                    <td><?php echo $row['nome']; ?></td>
                    <td><?php echo $row['cgu'] ?></td>
                    
                    <a href='editar.php?cgu=<?php echo $row['cgu']; ?>' class='link'>
                    <img alt='Edit' title='Edit' src='images/editar.png' width='15px' height='15px' hspace='10' /></a>

                    <a href='excluir.php?cgu=<?php echo $row['cgu']; ?>' class='link'>
                    <img alt='Delete' title='Delete' src='images/excluir.png' width='15px' height='15px' hspace='10' onclick='return Confirmadel()' /></a></td>
                </tr>

                <?php
                    $i++;
                    }
                ?>
            </table>
        </form>
    </body>
</html>