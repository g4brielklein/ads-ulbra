<?php

	require 'banco.php';

	$id = null;
	if ( !empty($_GET['id']))
            {
		$id = $_REQUEST['id'];
            }

	if ( null==$id )
            {
		header("Location: index.php");
            }

	if ( !empty($_POST))
            {

		$CatCodigoErro = null;
		$CatNomeErro = null;
		$CatGrupoErro = null;
        $CatSubGrupoErro = null;

		$CatCodigo = $_POST['CatCodigo'];
		$CatNome = $_POST['CatNome'];
		$CatGrupo = $_POST['CatGrupo'];
        $CatSubGrupo = $_POST['CatSubGrupo'];

		//Validação
		$validacao = true;
		if (empty($CatCodigo))
                {
                    $CatCodigoErro = 'Por favor digite o Código!';
                    $validacao = false;
                }

		if (empty($CatNome))
                {
                    $CatNomeErro = 'Por favor digite o Nome!';
                    $validacao = false;
		        }

		if (empty($CatGrupo))
                {
                    $CatGrupo = 'Por favor digite o Grupo!';
                    $validacao = false;
		        }

        if (empty($CatSubGrupo))
                {
                    $CatSubGrupo = 'Por favor digite o SubGrupo!';
                    $validacao = false;
		        }

		// update data
		if ($validacao)
                {
                    $pdo = Banco::conectar();
                    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
                    $sql = "UPDATE categorias  set CatNome = ?, CatGrupo = ?, CatSubGrupo = ? WHERE CatCodigo = ?";
                    $q = $pdo->prepare($sql);
                    $q->execute(array($CatNome,$CatGrupo,$CatSubGrupo,$CatCodigo));
                    Banco::desconectar();
                    header("Location: index.php");
		}
	}
        else
            {
                $pdo = Banco::conectar();
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$sql = "SELECT * FROM categorias where CatCodigo = ?";
		$q = $pdo->prepare($sql);
		$q->execute(array($id));
        $data = $q->fetch(PDO::FETCH_ASSOC);
        
		$CatCodigo = $data['CatCodigo'];
        $CatNome = $data['CatNome'];
        $CatGrupo = $data['CatGrupo'];
		$CatSubGrupo = $data['CatSubGrupo'];

		Banco::desconectar();
	}
?>

    <!DOCTYPE html>
    <html lang="pt-br">

    <head>
        <meta charset="utf-8">
        <!-- Latest compiled and minified CSS -->
        <link rel="stylesheet" href="assets/css/bootstrap.min.css">
				<title>Atualizar Categoria</title>
    </head>

    <body>
        <div class="container">

            <div class="span10 offset1">
							<div class="card">
								<div class="card-header">
                    <h3 class="well"> Atualizar Categoria </h3>
                </div>
								<div class="card-body">
                <form class="form-horizontal" action="update.php?id=<?php echo $id?>" method="post">

                    <div class="control-group <?php echo !empty($CatCodigoErro)?'error':'';?>">
                        <label class="control-label">Código</label>
                        <div class="controls">
                            <input name="CatCodigo" class="form-control" size="50" type="text" placeholder="Código" value="<?php echo !empty($CatCodigo)?$CatCodigo:'';?>">
                            <?php if (!empty($CatCodigoErro)): ?>
                                <span class="help-inline"><?php echo $CatCodigoErro;?></span>
                                <?php endif; ?>
                        </div>
                    </div>

                    <div class="control-group <?php echo !empty($CatNomeErro)?'error':'';?>">
                        <label class="control-label">Nome</label>
                        <div class="controls">
                            <input name="CatNome" class="form-control" size="80" type="text" placeholder="Nome" value="<?php echo !empty($CatNome)?$CatNome:'';?>">
                            <?php if (!empty($CatNomeErro)): ?>
                                <span class="help-inline"><?php echo $CatNomeErro;?></span>
                                <?php endif; ?>
                        </div>
                    </div>

                    <div class="control-group <?php echo !empty($CatGrupoErro)?'error':'';?>">
                        <label class="control-label">Grupo</label>
                        <div class="controls">
                            <input name="CatGrupo" class="form-control" size="30" type="text" placeholder="CGU" value="<?php echo !empty($CatGrupo)?$CatGrupo:'';?>">
                            <?php if (!empty($CatGrupoErro)): ?>
                                <span class="help-inline"><?php echo $CatGrupoErro;?></span>
                                <?php endif; ?>
                        </div>
                    </div>

                    <div class="control-group <?php echo !empty($CatSubGrupo)?'error':'';?>">
                        <label class="control-label">SubGrupo</label>
                        <div class="controls">
                            <input name="CatSubGrupo" class="form-control" size="40" type="text" placeholder="CPF" value="<?php echo !empty($CatSubGrupo)?$CatSubGrupo:'';?>">
                            <?php if (!empty($CatSubGrupoErro)): ?>
                                <span class="help-inline"><?php echo $CatSubGrupoErro;?></span>
                                <?php endif; ?>
                        </div>
                    </div>

                    <br/>
                    <div class="form-actions">
                        <button type="submit" class="btn btn-warning">Atualizar</button>
                        <a href="index.php" type="btn" class="btn btn-default">Voltar</a>
                    </div>
                </form>
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
