<?php
    /* Considerando o ano com 360 dias, sendo assim 5 anos possuem 1800 dias. */
    $tempoUtilizacao = rand(1,1800);
    $tempoRestante = 1800 - $tempoUtilizacao;
    echo "O aparelho possui uma utilização de ".$tempoUtilizacao." dias e 
    uma vida útil restante de ".$tempoRestante." dias";
?>