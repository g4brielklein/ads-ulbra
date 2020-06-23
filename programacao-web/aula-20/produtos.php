<!DOCTYPE html>
<html lang="pt-br">

<head>
    <meta charset="utf-8">
    <title>Adm Vendas - Produtos</title>
    <link rel="stylesheet" href="assets/css/bootstrap.min.css">
</head>

<body>
        <div class="container">
          <div class="jumbotron">
            <div class="row">
                <h2>Adm Vendas&nbsp<span class="badge badge-secondary"></span></h2><br>
                <h2>- Produtos<span class="badge badge-secondary"></span></h2>
            </div>
            Por Gabriel Klein
          </div>
            </br>
            <div class="row">
                <p>
                    <a href="createProd.php" class="btn btn-success">Adicionar Produto</a>
                </p>
                
                <table class="table table-striped">
                    <thead>
                        <tr>
                            <th scope="col">Código</th>
                            <th scope="col">Descrição</th>
                            <th scope="col">Categoria</th>
                            <th scope="col">Fornecedor</th>
                            <th scope="col">Preço de Venda</th>
                            <th scope="col">Margem de Lucro</th>
                            <th scope="col">Estoque</th>
                            <th scope="col">Ação</th>
                        </tr>
                    </thead>
                    <tbody>
                        <?php
                        include 'banco.php';
                        $pdo = Banco::conectar();
                        $sql = 'SELECT * FROM produtos';

                        foreach($pdo->query($sql)as $row)
                        {
                            echo '<tr>';
                            echo '<td>'. $row['ProCodigo'] . '</td>';
                            echo '<td>'. $row['ProDescricao'] . '</td>';
                            echo '<td>'. $row['CatCodigo'] . '</td>';
                            echo '<td>'. $row['ProFornecedor'] . '</td>';
                            echo '<td>'. $row['ProPrecoVenda'] . '</td>';
                            echo '<td>'. $row['ProMargemLucro'] . '</td>';
                            echo '<td>'. $row['ProEstoque'] . '</td>';

                            echo '<td width=250>';
                            echo ' ';
                            echo '<a class="btn btn-warning" href="update.php?id='.$row['ProCodigo'].'">Atualizar</a>';
                            echo ' ';
                            echo '<a class="btn btn-danger" href="delete.php?id='.$row['ProCodigo'].'">Excluir</a>';
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
