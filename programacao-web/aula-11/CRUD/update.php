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

		//Validação
		$validacao = true;
		if (empty($nome))
                {
                    $nomeErro = 'Por favor digite o nome!';
                    $validacao = false;
                }

		if (empty($cpf))
                {
                    $emailErro = 'Por favor digite o CPF!';
                    $validacao = false;
		}

		if (empty($endereco))
                {
                    $endereco = 'Por favor digite o endereço!';
                    $validacao = false;
		}

                if (empty($cgu))
                {
                    $telefone = 'Por favor digite o CGU!';
                    $validacao = false;
		}

                if (empty($idade))
                {
                    $endereco = 'Por favor preenche a idade!';
                    $validacao = false;
        }
        
        if (empty($altura))
                {
                    $endereco = 'Por favor preenche a altura!';
                    $validacao = false;
		}

		// update data
		if ($validacao)
                {
                    $pdo = Banco::conectar();
                    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
                    $sql = "UPDATE aluno  set nome = ?, endereco = ?, cgu = ?, cpf = ?, idade = ?, altura = ? WHERE id = ?";
                    $q = $pdo->prepare($sql);
                    $q->execute(array($nome,$endereco,$cgu,$cpf,$idade,$altura,$id));
                    Banco::desconectar();
                    header("Location: index.php");
		}
	}
        else
            {
                $pdo = Banco::conectar();
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$sql = "SELECT * FROM aluno where id = ?";
		$q = $pdo->prepare($sql);
		$q->execute(array($id));
		$data = $q->fetch(PDO::FETCH_ASSOC);
		$nome = $data['nome'];
                $endereco = $data['endereco'];
                $cgu = $data['cgu'];
		$cpf = $data['cpf'];
        $idade = $data['idade'];
        $altura = $data['altura'];
		Banco::desconectar();
	}
?>

    <!DOCTYPE html>
    <html lang="pt-br">

    <head>
        <meta charset="utf-8">
        <!-- Latest compiled and minified CSS -->
        <link rel="stylesheet" href="assets/css/bootstrap.min.css">
				<title>Atualizar Contato</title>
    </head>

    <body>
        <div class="container">

            <div class="span10 offset1">
							<div class="card">
								<div class="card-header">
                    <h3 class="well"> Atualizar Contato </h3>
                </div>
								<div class="card-body">
                <form class="form-horizontal" action="update.php?id=<?php echo $id?>" method="post">

                    <div class="control-group <?php echo !empty($nomeErro)?'error':'';?>">
                        <label class="control-label">Nome</label>
                        <div class="controls">
                            <input name="nome" class="form-control" size="50" type="text" placeholder="Nome" value="<?php echo !empty($nome)?$nome:'';?>">
                            <?php if (!empty($nomeErro)): ?>
                                <span class="help-inline"><?php echo $nomeErro;?></span>
                                <?php endif; ?>
                        </div>
                    </div>

                    <div class="control-group <?php echo !empty($enderecoErro)?'error':'';?>">
                        <label class="control-label">Endereço</label>
                        <div class="controls">
                            <input name="endereco" class="form-control" size="80" type="text" placeholder="Endereço" value="<?php echo !empty($endereco)?$endereco:'';?>">
                            <?php if (!empty($enderecoErro)): ?>
                                <span class="help-inline"><?php echo $enderecoErro;?></span>
                                <?php endif; ?>
                        </div>
                    </div>

                    <div class="control-group <?php echo !empty($cguErro)?'error':'';?>">
                        <label class="control-label">CGU</label>
                        <div class="controls">
                            <input name="cgu" class="form-control" size="30" type="text" placeholder="CGU" value="<?php echo !empty($cgu)?$cgu:'';?>">
                            <?php if (!empty($cguErro)): ?>
                                <span class="help-inline"><?php echo $cguErro;?></span>
                                <?php endif; ?>
                        </div>
                    </div>

                    <div class="control-group <?php echo !empty($cpf)?'error':'';?>">
                        <label class="control-label">CPF</label>
                        <div class="controls">
                            <input name="cpf" class="form-control" size="40" type="text" placeholder="CPF" value="<?php echo !empty($cpf)?$cpf:'';?>">
                            <?php if (!empty($cpfErro)): ?>
                                <span class="help-inline"><?php echo $cpfErro;?></span>
                                <?php endif; ?>
                        </div>
                    </div>

                    <div class="control-group <?php echo !empty($idade)?'error':'';?>">
                        <label class="control-label">Idade</label>
                        <div class="controls">
                            <input name="idade" class="form-control" size="40" type="text" placeholder="Idade" value="<?php echo !empty($idade)?$idade:'';?>">
                            <?php if (!empty($idadeErro)): ?>
                                <span class="help-inline"><?php echo $idadeErro;?></span>
                                <?php endif; ?>
                        </div>
                    </div>

                    <div class="control-group <?php echo !empty($altura)?'error':'';?>">
                        <label class="control-label">Altura</label>
                        <div class="controls">
                            <input name="altura" class="form-control" size="40" type="text" placeholder="Altura" value="<?php echo !empty($altura)?$altura:'';?>">
                            <?php if (!empty($alturaErro)): ?>
                                <span class="help-inline"><?php echo $alturaErro;?></span>
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
