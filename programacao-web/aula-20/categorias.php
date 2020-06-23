<!DOCTYPE html>
<html lang="pt-br">

<head>
    <meta charset="utf-8">
    <title>Adm Vendas</title>
    <link rel="stylesheet" href="assets/css/bootstrap.min.css">
</head>

<body>
        <div class="container">
          <div class="jumbotron">
            <div class="row">
                <h2>Adm Vendas&nbsp<span class="badge badge-secondary"></span></h2><br>
                <h2>- Categorias<span class="badge badge-secondary"></span></h2>
            </div>
            Por Gabriel Klein
          </div>
            </br>
            <div class="row">
                <p>
                    <a href="createCat.php" class="btn btn-success">Adicionar Categoria</a>
                </p>
                
                <table class="table table-striped">
                    <thead>
                        <tr>
                            <th scope="col">Código</th>
                            <th scope="col">Nome</th>
                            <th scope="col">Grupo</th>
                            <th scope="col">SubGrupo</th>
                            <th scope="col">Ação</th>
                        </tr>
                    </thead>
                    <tbody>
                        <?php
                        include 'banco.php';
                        $pdo = Banco::conectar();
                        $sql = 'SELECT * FROM categorias';

                        foreach($pdo->query($sql)as $row)
                        {
                            echo '<tr>';
                            echo '<td>'. $row['CatCodigo'] . '</td>';
                            echo '<td>'. $row['CatNome'] . '</td>';
                            echo '<td>'. $row['CatGrupo'] . '</td>';
                            echo '<td>'. $row['CatSubGrupo'] . '</td>';

                            echo '<td width=250>';
                            echo ' ';
                            echo '<a class="btn btn-warning" href="update.php?id='.$row['CatCodigo'].'">Atualizar</a>';
                            echo ' ';
                            echo '<a class="btn btn-danger" href="delete.php?id='.$row['CatCodigo'].'">Excluir</a>';
                            echo '</td>';
                            echo '</tr>';
                        }
                        Banco::desconectar();
                        ?>
                    </tbody>
                </table>
            </div>
        </div>
    <script src="https://code.jquery.com/jquery-3.3.1.js" integrity="sha256-2Kok7MbOyxpgUVvAk/HJ2jigOSYS2auK4Pfzbm7uH60=" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js" integrity="sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49" crossorigin="anonymous"></script>
    <script src="assets/js/bootstrap.min.js"></script>
</body>
</html>
