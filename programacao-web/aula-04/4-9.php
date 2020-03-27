<?php
    print("Aula 4 - Exemplo 4.9 - Por Gabriel Klein");
    print("<h2>Exemplo de operadores lógicos</h2>");
    $a = 10;
    $b = 2.5;
    $and = ($a > 0) AND ($b < 10); // Ou $and = ($a > 0) && ($b < 10);
    /* and retorna verdadeiro se $a for mais do que 0 E se $b for menor do que 10
    , do contrário, retorna falso */
    $or = ($a == 0) || ($b > 0); // Ou $or = ($a == 0) OR ($b > 0);
    /* $or retorna verdadeiro se $a for igual a 0 OU se $b for maior do que 0
    do contrário, retorna falso */
    $xor = ($a < 20) XOR ($b == 10);
    /* $xor retorna verdadeiro se $a for menor do que 20 (exclusivamente)
    OU se $b for igual a 10 (exclusivamente)
    do contrário, retorna falso */
    $negacao = !($a != 10);
    /* $negacao retorna verdadeiro se $a for igual a 10
    do contrário, retorna falso */
    print("AND: $and <br> OR: $or <br> XOR: $xor <br> Negação: $negacao");
    /* Se o resultado for falso retorna 0 e neste caso o valor não é escrito,
     ou seja, nada é apresentado como resultado */
?>