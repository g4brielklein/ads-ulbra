<?php
    print("Aula 4 - Exemplo 4.7 - Por Gabriel Klein");
    print("<h2>Exemplo de operadores aritméticos</h2>");
    $a = 10;
    $b = 2.5;
    $x = "Seja ";
    $y = "bem vindo!";
    $soma = $a + $b;
    $subtracao = $a - $b;
    $multiplicacao = $a * $b;
    $divisao = $a / $b;
    $modulo = $a % $b; // Retorna o resto da divisão inteira
    $concatenacao = $x.$y; // Junta o conteúdo da variável $y após o conteúdo da variável $x
    $a++;
    $b--;
    print("Soma: $soma <br> Subtração: $subtracao <br> Multiplicação: $multiplicacao
     <br> Divisão: $divisao <br> Módulo: $modulo <br> Concatenação: $concatenacao");
    print("<br> Incremento: $a <br> Decremento: $b"); 
?>