<!DOCTYPE html>
<html lang="pt-br">

<head>
    <meta charset="utf-8">
    <!-- Latest compiled and minified CSS -->
  <link rel="stylesheet" href="assets/css/bootstrap.min.css">
  <title>Adicionar Aluno</title>
</head>

<body>
    <div class="container">
        <div clas="span10 offset1">
          <div class="card">
            <div class="card-header">
                <h3 class="well"> Adicionar Aluno </h3>
            </div>
            <div class="card-body">
            <form class="form-horizontal" action="create.php" method="post">

                <div class="control-group <?php echo !empty($nomeErro)?'error ' : '';?>">
                    <label class="control-label">Nome</label>
                    <div class="controls">
                        <input size="50" class="form-control" name="nome" type="text" placeholder="Nome" required="" value="<?php echo !empty($nome)?$nome: '';?>">
                        <?php if(!empty($nomeErro)): ?>
                            <span class="help-inline"><?php echo $nomeErro;?></span>
                            <?php endif;?>
                    </div>
                </div>

                <div class="control-group <?php echo !empty($enderecoErro)?'error ': '';?>">
                    <label class="control-label">Endereço</label>
                    <div class="controls">
                        <input size="80" class="form-control" name="endereco" type="text" placeholder="Endereço" required="" value="<?php echo !empty($endereco)?$endereco: '';?>">
                        <?php if(!empty($emailErro)): ?>
                            <span class="help-inline"><?php echo $enderecoErro;?></span>
                            <?php endif;?>
                    </div>
                </div>

                <div class="control-group <?php echo !empty($cguErro)?'error ': '';?>">
                    <label class="control-label">CGU</label>
                    <div class="controls">
                        <input size="35" class="form-control" name="cgu" type="text" placeholder="CGU" required="" value="<?php echo !empty($cgu)?$cgu: '';?>">
                        <?php if(!empty($cguErro)): ?>
                            <span class="help-inline"><?php echo $cguErro;?></span>
                            <?php endif;?>
                    </div>
                </div>

                <div class="control-group <?php echo !empty($cpfErro)?'error ': '';?>">
                    <label class="control-label">CPF</label>
                    <div class="controls">
                        <input size="40" class="form-control" name="cpf" type="text" placeholder="CPF" required="" value="<?php echo !empty($cpf)?$cpf: '';?>">
                        <?php if(!empty($cpfErro)): ?>
                            <span class="help-inline"><?php echo $cpfErro;?></span>
                            <?php endif;?>
                    </div>
                </div>

                <div class="control-group <?php echo !empty($idadeErro)?'error ': '';?>">
                    <label class="control-label">Idade</label>
                    <div class="controls">
                        <input size="35" class="form-control" name="idade" type="text" placeholder="Idade" required="" value="<?php echo !empty($idade)?$idade: '';?>">
                        <?php if(!empty($idadeErro)): ?>
                            <span class="help-inline"><?php echo $idadeErro;?></span>
                            <?php endif;?>
                    </div>
                </div>

                <div class="control-group <?php echo !empty($alturaErro)?'error ': '';?>">
                    <label class="control-label">Altura</label>
                    <div class="controls">
                        <input size="35" class="form-control" name="altura" type="text" placeholder="Altura" required="" value="<?php echo !empty($altura)?$altura: '';?>">
                        <?php if(!empty($alturaErro)): ?>
                            <span class="help-inline"><?php echo $alturaErro;?></span>
                            <?php endif;?>
                    </div>
                </div>

                <div class="form-actions">
                    <br/>

                    <button type="submit" class="btn btn-success">Adicionar</button>
                    <a href="index.php" type="btn" class="btn btn-default">Voltar</a>

                </div>
            </form>
          </div>
        </div>
        </div>
    </div>
    </div>
    <script src="https://code.jquery.com/jquery-3.3.1.js" integrity="sha256-2Kok7MbOyxpgUVvAk/HJ2jigOSYS2auK4Pfzbm7uH60=" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js" integrity="sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49" crossorigin="anonymous"></script>
    <!-- Latest compiled and minified JavaScript -->
    <script src="assets/js/bootstrap.min.js"></script>
</body>

</html>

<?php
    require 'banco.php';

    if(!empty($_POST))
    {
        //Acompanha os erros de validação
        $nomeErro = null;
        $enderecoErro = null;
        $cguErro = null;
        $cpfErro = null;
        $idadeErro = null;
        $alturaErro = null;

        $nome = $_POST['nome'];
        $endereco = $_POST['endereco'];
        $cgu = $_POST['cgu'];
        $cpf = $_POST['cpf'];
        $idade = $_POST['idade'];
        $altura = $_POST['altura'];

        //Validaçao dos campos:
        $validacao = true;
        if(empty($nome))
        {
            $nomeErro = 'Por favor digite o seu nome!';
            $validacao = false;
        }

        if(empty($endereco))
        {
            $enderecoErro = 'Por favor digite o seu endereço!';
            $validacao = false;
        }

        if(empty($cgu))
        {
            $cguErro = 'Por favor digite o CGU!';
            $validacao = false;
        }

        if(empty($cpf))
        {
            $cpfError = 'Por favor digite o seu CPF';
            $validacao = false;
        }

        //Inserindo no Banco:
        if($validacao)
        {
            $pdo = Banco::conectar();
            $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
            $sql = "INSERT INTO aluno (nome, endereco, cgu, cpf, idade, altura) VALUES(?,?,?,?,?,?)";
            $q = $pdo->prepare($sql);
            $q->execute(array($nome,$endereco,$cgu,$cpf,$idade,$altura));
            Banco::desconectar();
            header("Location: index.php");
        }
    }
?>
