<?php
    print("Aula 5 - Exemplo 10 - Por Gabriel Klein");
    print("<br><br>");
    $mes = [
        "Janeiro", "Fevereiro",
        "Março", "Abril",
        "Maio", "Junho",
        "Julho", "Agosto",
        "Setembro", "Outubro",
        "Novembro", "Dezembro"
    ];
    $numMes = 5;
    if($numMes >=1 && $numMes <=12){
        echo $mes[$numMes - 1];
    }else{
        echo "Mês inválido";
    }
?>