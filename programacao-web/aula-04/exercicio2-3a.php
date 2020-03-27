<?php
    // Variáveis
    $idioma = 'Português'; // String
    $anoLancamento = 2015 + 1; // Integer
    $preco = 25.50; // Double
    $disponivelVenda = true; // Boolean

    // Exibindo o conteúdo das variáveis
    echo "Livro - Exercitando a programação com PHP<br/>";
    echo "Idioma: ".$idioma."<br/>";
    echo "Ano Lançamento: ".$anoLancamento."<br/>";
    echo "Preço: ".$preco."<br/>";
    echo "Disponível em estoque: ";
    if($disponivelVenda){echo"Sim";}else{echo"Não";}
?>