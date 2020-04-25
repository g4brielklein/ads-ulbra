<!DOCTYPE html>
<html>
    <head>
    </head>
        <meta charset="UTF-8">
        <title>Banco de Dados</title>
        <style>
            body {
                background-color: #3b5998;
                color: white;
                padding: 10px;
            }

            h1 {
                font-size: 22px;
            }

            #banco {
                border: 1px solid white;
                padding: 10px;
                width: 200px;
            }
        </style>

        </style>
    </body>
        <h1>Database</h1>
        <div id="banco">
            <?php

            $servidor = 'localhost';
            $user = 'root';
            $senha = '';
            $banco = 'ulbra';
            $TAB = '&nbsp;&nbsp;&nbsp;&nbsp;';

            $conect = mysqli_connect($servidor, $user, $senha);
            $db = mysqli_select_db($conect, $banco);

            $query_select = 'SELECT * FROM aluno';
            $select = mysqli_query($conect, $query_select);
            $fetch = mysqli_fetch_row($select);

            echo $TAB.$TAB.'CGU '.$TAB.$TAB.$TAB.'Nome <br/><br>';

            echo $fetch[0].$TAB.$fetch[1].'<br/>';

            while ($fetch = mysqli_fetch_row($select)) {
                echo $fetch[0].$TAB.$fetch[1].'<br/>';
            }

            ?>
        </div>
    </body>
</html>