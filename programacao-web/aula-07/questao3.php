<?php
    $altura_chico = 150;
    $altura_juca = 110;
    $anos = 0;
    while ($altura_chico >= $altura_juca)
    {
        $anos++;
        $altura_chico+=2;
        $altura_juca+=3;
    }
    print("Serão necessários $anos anos para que Juca seja maior que Chico");
?>