<!DOCTYPE html>
<html lang="pt-br">

<head>
    <meta charset="utf-8">
    <title>Adm Vendas - Fornecedores</title>
    <link rel="stylesheet" href="assets/css/bootstrap.min.css">
</head>

<body>
        <div class="container">
          <div class="jumbotron">
            <div class="row">
                <h2>Adm Vendas&nbsp<span class="badge badge-secondary"></span></h2><br>
                <h2>- Fornecedores<span class="badge badge-secondary"></span></h2>
            </div>
            Por Gabriel Klein
          </div>
            </br>
            <div class="row">
                <p>
                    <a href="createCat.php" class="btn btn-success">Adicionar Fornecedor</a>
                </p>
                
                <table class="table table-striped">
                    <thead>
                        <tr>
                            <th scope="col">Código</th>
                            <th scope="col">Nome</th>
                            <th scope="col">Fantasia</th>
                            <th scope="col">CNPJ</th>
                            <th scope="col">Endereço</th>
                            <th scope="col">Fone</th>
                            <th scope="col">Ação</th>
                        </tr>
                    </thead>
                    <tbody>
                        <?php
                        include 'banco.php';
                        $pdo = Banco::conectar();
                        $sql = 'SELECT * FROM fornecedores';

                        foreach($pdo->query($sql)as $row)
                        {
                            echo '<tr>';
                            echo '<td>'. $row['ForCodigo'] . '</td>';
                            echo '<td>'. $row['ForNome'] . '</td>';
                            echo '<td>'. $row['ForFantasia'] . '</td>';
                            echo '<td>'. $row['ForCNPJ'] . '</td>';
                            echo '<td>'. $row['ForEndereco'] . '</td>';
                            echo '<td>'. $row['ForFone'] . '</td>';


                            echo '<td width=250>';
                            echo ' ';
                            echo '<a class="btn btn-warning" href="update.php?id='.$row['ForCodigo'].'">Atualizar</a>';
                            echo ' ';
                            echo '<a class="btn btn-danger" href="delete.php?id='.$row['ForCodigo'].'">Excluir</a>';
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
