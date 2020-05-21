<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>AdmVendas</title>
    <link rel="stylesheet" href="assets/css/bootstrap.min.css">
</head>

<body>
        <div class="container">
          <div class="jumbotron">
            <div class="row">
                <h2>AdmVendas<span class="badge badge-secondary"></span></h2>
            </div>
          </div>
            </br>
            <div class="row">
                <p>
                    <a href="create.php" class="btn btn-success">Adicionar</a>
                </p>
                <table class="table table-striped">
                    <thead>
                        <tr>
                            <th scope="col">Código</th>
                            <th scope="col">Nome</th>
                            <th scope="col">Grupo</th>
                            <th scope="col">SubGrupo</th>
                        </tr>
                    </thead>
                    <tbody>
                        <?php
                        include 'banco.php';
                        $pdo = Banco::conectar();
                        $sql = 'SELECT * FROM tbCategorias';

                        foreach($pdo->query($sql)as $row)
                        {
                            echo '<tr>';
                            echo '<td>'. $row['catCodigo'] . '</td>';
                            echo '<td>'. $row['catNome'] . '</td>';
                            echo '<td>'. $row['catGrupo'] . '</td>';
                            echo '<td>'. $row['catSubGrupo'] . '</td>';
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