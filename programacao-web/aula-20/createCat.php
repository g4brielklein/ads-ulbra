<!DOCTYPE html>
<html lang="pt-br">

<head>
    <meta charset="utf-8">
    <title>Cadastro de Categorias</title>
    <link rel="stylesheet" href="assets/css/bootstrap.min.css">
</head>

<body>
    <div class="container">
        <div clas="span10 offset1">
          <div class="card">
            <div class="card-header">
                <h3 class="well">Cadastro de Categorias</h3>
            </div>
            <div class="card-body">
            <form class="form-horizontal" action="createCat.php" method="post">

                <div class="control-group <?php echo !empty($CatCodigoErro)?'error ' : '';?>">
                    <label class="control-label">Código</label>
                    <div class="controls">
                        <input size="50" class="form-control" name="CatCodigo" type="text" placeholder="Código" required="" value="<?php echo !empty($CatCodigo)?$CatCodigo: '';?>">
                        <?php if(!empty($CatCodigoErro)): ?>
                            <span class="help-inline"><?php echo $CatCodigoErro;?></span>
                            <?php endif;?>
                    </div>
                </div>

                <div class="control-group <?php echo !empty($CatNomeErro)?'error ' : '';?>">
                    <label class="control-label">Nome</label>
                    <div class="controls">
                        <input size="50" class="form-control" name="CatNome" type="text" placeholder="Nome" required="" value="<?php echo !empty($CatNome)?$CatNome: '';?>">
                        <?php if(!empty($CatNomeErro)): ?>
                            <span class="help-inline"><?php echo $CatNomeErro;?></span>
                            <?php endif;?>
                    </div>
                </div>

                <div class="control-group <?php echo !empty($CatGrupoErro)?'error ': '';?>">
                    <label class="control-label">Grupo</label>
                    <div class="controls">
                        <input size="80" class="form-control" name="CatGrupo" type="text" placeholder="Grupo" required="" value="<?php echo !empty($CatGrupo)?$CatGrupo: '';?>">
                        <?php if(!empty($CatGrupoErro)): ?>
                            <span class="help-inline"><?php echo $CatGrupoErro;?></span>
                            <?php endif;?>
                    </div>
                </div>

                <div class="control-group <?php echo !empty($CatSubGrupoErro)?'error ': '';?>">
                    <label class="control-label">SubGrupo</label>
                    <div class="controls">
                        <input size="35" class="form-control" name="CatSubGrupo" type="text" placeholder="SubGrupo" required="" value="<?php echo !empty($CatSubGrupo)?$CatSubGrupo: '';?>">
                        <?php if(!empty($CatSubGrupoErro)): ?>
                            <span class="help-inline"><?php echo $CatSubGrupoErro;?></span>
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
        $CatCodigoErro = null;
        $CatNomeErro = null;
        $CatGrupoErro = null;
        $CatSubGrupoErro = null;
        
        $CatCodigo = $_POST['CatCodigo'];
        $CatNome = $_POST['CatNome'];
        $CatGrupo = $_POST['CatGrupo'];
        $CatSubGrupo = $_POST['CatSubGrupo'];

        //Validaçao dos campos:
        $validacao = true;

        if(empty($CatCodigo))
        {
            $CatCodigoErro = 'Por favor digite o código da categoria!';
            $validacao = false;
        }

        if(empty($CatNome))
        {
            $CatNomeErro = 'Por favor digite o nome da categoria!';
            $validacao = false;
        }

        if(empty($CatGrupo))
        {
            $CatGrupoErro = 'Por favor digite o grupo da categoria!';
            $validacao = false;
        }

        if(empty($CatSubGrupo))
        {
            $CatSubGrupoErro = 'Por favor digite o subgrupo da categoria!';
            $validacao = false;
        }

        //Inserindo no Banco:
        if($validacao)
        {
            $pdo = Banco::conectar();
            $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
            $sql = "INSERT INTO categorias (CatCodigo, CatNome, CatGrupo, CatSubGrupo) VALUES(?,?,?,?)";
            $q = $pdo->prepare($sql);
            $q->execute(array($CatCodigo,$CatNome,$CatGrupo,$CatSubGrupo));
            Banco::desconectar();
            header("Location: categorias.php");
        }
    }
?>
