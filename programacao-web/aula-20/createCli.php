<!DOCTYPE html>
<html lang="pt-br">

<head>
    <meta charset="utf-8">
    <title>Cadastro de Clientes</title>
    <link rel="stylesheet" href="assets/css/bootstrap.min.css">
</head>

<body>
    <div class="container">
        <div clas="span10 offset1">
          <div class="card">
            <div class="card-header">
                <h3 class="well">Cadastro de Clientes</h3>
            </div>
            <div class="card-body">
            <form class="form-horizontal" action="createCli.php" method="post">

                <div class="control-group <?php echo !empty($CliCodigoErro)?'error ' : '';?>">
                    <label class="control-label">Código</label>
                    <div class="controls">
                        <input size="50" class="form-control" name="CliCodigo" type="text" placeholder="Código" required="" value="<?php echo !empty($CliCodigo)?$CliCodigo: '';?>">
                        <?php if(!empty($CliCodigoErro)): ?>
                            <span class="help-inline"><?php echo $CliCodigoErro;?></span>
                            <?php endif;?>
                    </div>
                </div>

                <div class="control-group <?php echo !empty($CliNomeErro)?'error ' : '';?>">
                    <label class="control-label">Nome</label>
                    <div class="controls">
                        <input size="50" class="form-control" name="CliNome" type="text" placeholder="Nome" required="" value="<?php echo !empty($CliNome)?$CliNome: '';?>">
                        <?php if(!empty($CliNomeErro)): ?>
                            <span class="help-inline"><?php echo $CliNomeErro;?></span>
                            <?php endif;?>
                    </div>
                </div>

                <div class="control-group <?php echo !empty($CliCPFErro)?'error ': '';?>">
                    <label class="control-label">CPF</label>
                    <div class="controls">
                        <input size="80" class="form-control" name="CliCPF" type="text" placeholder="CPF" required="" value="<?php echo !empty($CliCPF)?$CliCPF: '';?>">
                        <?php if(!empty($CliCPFErro)): ?>
                            <span class="help-inline"><?php echo $CliCPFErro;?></span>
                            <?php endif;?>
                    </div>
                </div>

                <div class="control-group <?php echo !empty($CliCNPJErro)?'error ': '';?>">
                    <label class="control-label">CNPJ</label>
                    <div class="controls">
                        <input size="35" class="form-control" name="CliCNPJ" type="text" placeholder="CNPJ" required="" value="<?php echo !empty($CliCNPJ)?$CliCNPJ: '';?>">
                        <?php if(!empty($CliCNPJErro)): ?>
                            <span class="help-inline"><?php echo $CliCNPJErro;?></span>
                            <?php endif;?>
                    </div>
                </div>

                <div class="control-group <?php echo !empty($CliEnderecoErro)?'error ': '';?>">
                    <label class="control-label">Endereço</label>
                    <div class="controls">
                        <input size="35" class="form-control" name="CliEndereco" type="text" placeholder="Endereço" required="" value="<?php echo !empty($CliEndereco)?$CliEndereco: '';?>">
                        <?php if(!empty($CliEnderecoErro)): ?>
                            <span class="help-inline"><?php echo $CliEnderecoErro;?></span>
                            <?php endif;?>
                    </div>
                </div>

                <div class="control-group <?php echo !empty($CliBairroErro)?'error ': '';?>">
                    <label class="control-label">Bairro</label>
                    <div class="controls">
                        <input size="35" class="form-control" name="CliBairro" type="text" placeholder="Bairro" required="" value="<?php echo !empty($CliBairro)?$CliBairro: '';?>">
                        <?php if(!empty($CliBairroErro)): ?>
                            <span class="help-inline"><?php echo $CliCNPJBairro;?></span>
                            <?php endif;?>
                    </div>
                </div>

                <div class="form-actions">
                    <br/>

                    <button type="submit" class="btn btn-success">Adicionar</button>
                    <a href="clientes.php" type="btn" class="btn btn-default">Voltar</a>

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
        $CliCodigoErro = null;
        $CliNomeErro = null;
        $CliCPFErro = null;
        $CliCNPJErro = null;
        $CliEnderecoErro = null;
        $CliBairroErro = null;

        
        $CliCodigo = $_POST['CliCodigo'];
        $CliNome = $_POST['CliNome'];
        $CliCPF = $_POST['CliCPF'];
        $CliCNPJ = $_POST['CliCNPJ'];
        $CliEndereco = $_POST['CliEndereco'];
        $CliBairro = $_POST['CliBairro'];


        //Validaçao dos campos:
        $validacao = true;

        if(empty($CliCodigo))
        {
            $CliCodigoErro = 'Por favor digite o código da categoria!';
            $validacao = false;
        }

        if(empty($CliNome))
        {
            $CliNomeErro = 'Por favor digite o nome da categoria!';
            $validacao = false;
        }

        if(empty($CliCPF))
        {
            $CliCPFErro = 'Por favor digite o grupo da categoria!';
            $validacao = false;
        }

        if(empty($CliCNPJ))
        {
            $CliCNPJErro = 'Por favor digite o subgrupo da categoria!';
            $validacao = false;
        }

        if(empty($CliEndereco))
        {
            $CliEnderecoErro = 'Por favor digite o grupo da categoria!';
            $validacao = false;
        }

        if(empty($CliBairo))
        {
            $CliBairoErro = 'Por favor digite o subgrupo da categoria!';
            $validacao = false;
        }

        //Inserindo no Banco:
        if($validacao)
        {
            $pdo = Banco::conectar();
            $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
            $sql = "INSERT INTO clientes (CliCodigo, CliNome, CliCPF, CliCNPJ, CliEndereco, CliBairro) VALUES(?,?,?,?,?,?)";
            $q = $pdo->prepare($sql);
            $q->execute(array($CliCodigo,$CliNome,$CliCPF,$CliCNPJ,$CliEndereco,$CliBairro));
            Banco::desconectar();
            header("Location: clientes.php");
        }
    }
?>
