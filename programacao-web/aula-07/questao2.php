<?php
    $nome = 'Gabriel';
    $sexo = 'M';
    $idade = 20;
    if ($sexo == 'F') {
        if ($idade >= 18) {
            print("F-MAIOR");
        } else {
            print("F-MENOR");
        }
    }
    if ($sexo == 'M') {
        if ($idade >= 18) {
            print("M-MAIOR");
        } else {
            print("M-MENOR");
        }
    }
?>