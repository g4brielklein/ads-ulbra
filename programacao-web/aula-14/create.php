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
            <form class="form-horizontal" action="create.php" method="post">

                <div class="control-group <?php echo !empty($catCodigoErro)?'error ' : '';?>">
                    <label class="control-label">Código</label>
                    <div class="controls">
                        <input size="50" class="form-control" name="catCodigo" type="text" placeholder="Código" required="" value="<?php echo !empty($catCodigo)?$catCodigo: '';?>">
                        <?php if(!empty($catCodigoErro)): ?>
                            <span class="help-inline"><?php echo $catCodigoErro;?></span>
                            <?php endif;?>
                    </div>
                </div>

                <div class="control-group <?php echo !empty($catNomeErro)?'error ' : '';?>">
                    <label class="control-label">Nome</label>
                    <div class="controls">
                        <input size="50" class="form-control" name="catNome" type="text" placeholder="Nome" required="" value="<?php echo !empty($catNome)?$catNome: '';?>">
                        <?php if(!empty($catNomeErro)): ?>
                            <span class="help-inline"><?php echo $catNomeErro;?></span>
                            <?php endif;?>
                    </div>
                </div>

                <div class="control-group <?php echo !empty($catGrupoErro)?'error ': '';?>">
                    <label class="control-label">Grupo</label>
                    <div class="controls">
                        <input size="80" class="form-control" name="catGrupo" type="text" placeholder="Grupo" required="" value="<?php echo !empty($catGrupo)?$catGrupo: '';?>">
                        <?php if(!empty($catGrupoErro)): ?>
                            <span class="help-inline"><?php echo $catGrupoErro;?></span>
                            <?php endif;?>
                    </div>
                </div>

                <div class="control-group <?php echo !empty($catSubGrupoErro)?'error ': '';?>">
                    <label class="control-label">SubGrupo</label>
                    <div class="controls">
                        <input size="35" class="form-control" name="catSubGrupo" type="text" placeholder="SubGrupo" required="" value="<?php echo !empty($catSubGrupo)?$catSubGrupo: '';?>">
                        <?php if(!empty($catSubGrupoErro)): ?>
                            <span class="help-inline"><?php echo $catSubGrupoErro;?></span>
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
        $catCodigoErro = null;
        $catNomeErro = null;
        $catGrupoErro = null;
        $catSubGrupoErro = null;
        
        $catCodigo = $_POST['catCodigo'];
        $catNome = $_POST['catNome'];
        $catGrupo = $_POST['catGrupo'];
        $catSubGrupo = $_POST['catSubGrupo'];

        //Validaçao dos campos:
        $validacao = true;

        if(empty($catCodigo))
        {
            $catCodigoErro = 'Por favor digite o código da categoria!';
            $validacao = false;
        }

        if(empty($catNome))
        {
            $catNomeErro = 'Por favor digite o nome da categoria!';
            $validacao = false;
        }

        if(empty($catGrupo))
        {
            $catGrupoErro = 'Por favor digite o grupo da categoria!';
            $validacao = false;
        }

        if(empty($catSubGrupo))
        {
            $catSubGrupoErro = 'Por favor digite o subgrupo da categoria!';
            $validacao = false;
        }

        //Inserindo no Banco:
        if($validacao)
        {
            $pdo = Banco::conectar();
            $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
            $sql = "INSERT INTO tbCategorias (catCodigo, catNome, catGrupo, catSubGrupo) VALUES(?,?,?,?)";
            $q = $pdo->prepare($sql);
            $q->execute(array($catCodigo,$catNome,$catGrupo,$catSubGrupo));
            Banco::desconectar();
            header("Location: index.php");
        }
    }
?>
