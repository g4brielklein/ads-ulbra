// Obs: O JavaScript atribui o tipo da variável automaticamente com base
// no conteúdo atribuido à variável, então, como foi solicitado no trabalho
// os tipos, colocaremos como comentário ao lado das variáveis.

// Variáveis para a análise
let valor_da_compra = 897.00 // float
let possui_renda = 1; // boolean
let renda_mensal = 2949.00 //float
let cadastrado_spc = 0; // boolean | 1 = true, 0 = false
let idade = 22; // int
let emancipado = 0; // boolean
let quantidade_compras = 2; // int
let compra_em_atraso = 0; // boolean (se existem compras em atraso ou não)
let dias_atraso = 0; // int (dias de atraso, caso a variável anterior for positiva)
let acordo = 0; // boolean (se existem acordos ou não)
let dias_atraso_acordo = 0; // int (dias de atraso no pagamento do acordo, caso a variável anterior for positiva)
let dependente = 0; // boolean (se o cliente é dependente de outra conta ou não)

// Variáveis do sistema
const salario_minimo = 1292.82
let faixa_etaria = null
let faixa = null

// Regras
if (renda_mensal < 1292.82) {
    faixa = 'Menos de um salário minímo' 
} else if (renda_mensal >= 1292.82 && renda_mensal < (salario_minimo * 6)) {
    faixa = 'Entre 1 e 5 salários'    
} else if ((renda_mensal >= (salario_minimo * 6)) && (renda_mensal < (salario_minimo * 11))) {
    faixa = 'Entre 6 e 10 salários'
} else if (renda_mensal > (salario_minimo * 10)) {
    faixa = 'Mais de 10 salários'
}

if ( idade >= 18 || emancipado == true ) {
    faixa_etaria = 'Maior de idade'
} else if (idade >= 18 && idade <= 65) {
    faixa_etaria = 'Faixa produtiva'
} else if (idade > 60) {
    faixa_etaria = 'Idoso'
}

if (dias_atraso > 90 || dias_atraso_acordo >= 1) {
    console.log('O crédito não foi liberado devido à contas em atraso.')
}

if (quantidade_compras >= 1) {
    if (dias_atraso_acordo >= 30 && dias_atraso_acordo <= 45) {
        console.log('Crédito liberado com fator de confiança de 60%')
    }
    if (dias_atraso_acordo >= 30 && dias_atraso_acordo <= 45 && idade < 18 && valor_da_compra < 350.00
        || dias_atraso_acordo >= 30 && dias_atraso_acordo <= 45 && idade < 18 && valor_da_compra < 350.00 && dependente == true) {
        console.log('Crédito liberado com fator de confiança de 60%')
    }
}

if (cadastrado_spc == 1) {
    if (idade >= 18 
        && (faixa >= (salario_minimo * 5) && faixa < (salario_minimo * 11))
        && quantidade_compras > 5
        && compra_em_atraso == 0
        && acordo == 0
        ) {
            console.log('Crédito liberado')
    } else {
        console.log('Crédito bloqueado')
    }
}

if (valor_da_compra > (renda_mensal * 0.30)){
    console.log('Crédito bloqueado! | Valor do crédito superior à 30% da renda do cliente.')
}