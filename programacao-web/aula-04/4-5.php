<?php
    print("<h2>Exemplo de variáveis e constantes</h2>");
    $b = 17;
    $c = 7.5;
    $d = "Texto!";
    print ("Variável b: $b <br> Variável c: $c <br> Variável d: $d");
    define("VAR1", "Olá!");
    define("VAR2", 55.75);
    define("IDADE", 18);
    echo "<p>Constante VAR1: ".VAR1;
    echo "<br>Constante VAR2: ".VAR2."<br>Constante IDADE: ".IDADE;
    // Comentário em PHP - para 1 linha
    /*
    Também pode ser assim - para mais de uma linha
    */
?>