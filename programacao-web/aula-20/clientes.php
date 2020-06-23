<!DOCTYPE html>
<html lang="pt-br">

<head>
    <meta charset="utf-8">
    <title>Adm Vendas - Clientes</title>
    <link rel="stylesheet" href="assets/css/bootstrap.min.css">
</head>

<body>
        <div class="container">
          <div class="jumbotron">
            <div class="row">
                <h2>Adm Vendas&nbsp<span class="badge badge-secondary"></span></h2><br>
                <h2>- Clientes<span class="badge badge-secondary"></span></h2>
            </div>
            Por Gabriel Klein
          </div>
            </br>
            <div class="row">
                <p>
                    <a href="createCli.php" class="btn btn-success">Adicionar Cliente</a>
                </p>
                
                <table class="table table-striped">
                    <thead>
                        <tr>
                            <th scope="col">Código</th>
                            <th scope="col">Nome</th>
                            <th scope="col">CPF</th>
                            <th scope="col">CNPJ</th>
                            <th scope="col">Endereço</th>
                            <th scope="col">Bairro</th>
                            <th scope="col">Ação</th>
                        </tr>
                    </thead>
                    <tbody>
                        <?php
                        include 'banco.php';
                        $pdo = Banco::conectar();
                        $sql = 'SELECT * FROM clientes';

                        foreach($pdo->query($sql)as $row)
                        {
                            echo '<tr>';
                            echo '<td>'. $row['CliCodigo'] . '</td>';
                            echo '<td>'. $row['CliNome'] . '</td>';
                            echo '<td>'. $row['CliCPF'] . '</td>';
                            echo '<td>'. $row['CliCNPJ'] . '</td>';
                            echo '<td>'. $row['CliEndereco'] . '</td>';
                            echo '<td>'. $row['CliBairro'] . '</td>';


                            echo '<td width=250>';
                            echo ' ';
                            echo '<a class="btn btn-warning" href="update.php?id='.$row['CliCodigo'].'">Atualizar</a>';
                            echo ' ';
                            echo '<a class="btn btn-danger" href="delete.php?id='.$row['CliCodigo'].'">Excluir</a>';
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
