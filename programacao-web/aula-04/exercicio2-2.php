<html>
    <head>
        <title>Exercício 2</title>
    </head>
    <body>
        Exemplo de utilização de variáveis: <br><br>
        <?php
            $inteiro = 10;
            $real = 20.0;
            $caracter = 'V';
            $cor1 = "#FF0000";
            $cor2 = "#0000FF";
        ?>
        <font color=<?php echo $cor2 ?>>A variável $real tem
         o valor <?php echo $real ?>.</font> <br>
        <font color=<?php echo $cor1 ?>>O caracter escolhido
         é o <?php echo $caracter ?>.</font> <br>
    </body>
</html>