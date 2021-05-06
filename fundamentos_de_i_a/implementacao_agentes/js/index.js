// define celulas das ruas por onde os agente vão percorrer
let celulas = [
    {
        celula: 1,
        endereco: 2.0.toFixed(1)
    },
    {
        celula: 2,
        endereco: 2.1.toFixed(1)
    },
    {
        celula: 3,
        endereco: 2.2.toFixed(1)
    },
    {
        celula: 4,
        endereco: 2.3.toFixed(1)
    },
    {
        celula: 5,
        endereco: 2.4.toFixed(1)
    },
    {
        celula: 6,
        endereco: 2.5.toFixed(1)
    },
    {
        celula: 7,
        endereco: 2.6.toFixed(1)
    },
    {
        celula: 8,
        endereco: 2.7.toFixed(1)
    },
    {
        celula: 9,
        endereco: 3.7.toFixed(1)
    },
    {
        celula: 10,
        endereco: 4.7.toFixed(1)
    },
    {
        celula: 11,
        endereco: 4.6.toFixed(1)
    },
    {
        celula: 12,
        endereco: 4.5.toFixed(1)
    },
    {
        celula: 13,
        endereco: 4.4.toFixed(1)
    },
    {
        celula: 14,
        endereco: 4.3.toFixed(1)
    },
    {
        celula: 15,
        endereco: 4.2.toFixed(1)
    },
    {
        celula: 16,
        endereco: 4.1.toFixed(1)
    },
    {
        celula: 17,
        endereco: 4.0.toFixed(1)
    },
    {
        celula: 18,
        endereco: 3.0.toFixed(1)
    }
    
] 

// gera veiculos randomicamente na matriz
const vagas = [1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 3.1, 3.2, 3.3, 3.4, 3.5, 3.6];
let vagaRandomica1 = Math.floor(Math.random() * vagas.length)
let vagaRandomica2 = Math.floor(Math.random() * vagas.length)
let vagaRandomica3 = Math.floor(Math.random() * vagas.length)
let vagaRandomica4 = Math.floor(Math.random() * vagas.length)

let vaga1 = document.getElementById((vagas[vagaRandomica1]))
vaga1.innerHTML = 'V'
vaga1.pago = true

let vaga2 = document.getElementById((vagas[vagaRandomica2]))
vaga2.innerHTML = 'V'
vaga2.pago = false

let vaga3 = document.getElementById((vagas[vagaRandomica3]))
vaga3.innerHTML = 'V'
vaga3.pago = true

let vaga4 = document.getElementById((vagas[vagaRandomica4]))
vaga4.innerHTML = 'V'
vaga4.pago = false

// Percorre as céulas e marca os veiculos 

for (let i = 0; i < celulas.length; i++) {
    
    let cima = (document.getElementById(celulas[i].endereco).id - 1.0).toFixed(1)
    let atual = document.getElementById(celulas[i].endereco).id


    setTimeout(function(){ 

        // marca celula atual com F
        document.getElementById(celulas[i].endereco).innerHTML = 'F'

        // Verifica se a celula de cima é 'V'
        if (document.getElementById(cima).innerHTML == 'V') {
            let veiculo = document.getElementById(cima)
            if (veiculo.pago == true) {
                veiculo.innerHTML = 'VR'
            }
        
            if (veiculo.pago == false) {
                veiculo.innerHTML = 'VI'
            }
        }

     }, i*1000);

     setTimeout(function(){ 
        document.getElementById(celulas[i].endereco).innerHTML = ''
     }, i*1050);
     console.log(i*1050)
}

for (let j = 0; j < celulas.length; j++) {
    
    let cima = (document.getElementById(celulas[j].endereco).id - 1.0).toFixed(1)
    let atual = document.getElementById(celulas[j].endereco).id


    setTimeout(function(){ 

        // marca celula atual com F
        document.getElementById(celulas[j].endereco).innerHTML = 'G'

        // Verifica se a celula de cima é 'VI'
        if (document.getElementById(cima).innerHTML == 'VI') {
            let veiculo = document.getElementById(cima)
            veiculo.innerHTML = 'L'

            let deposito = [5.1, 5.2, 5.3, 5.4, 5.5]
            if (document.getElementById(deposito[0]).innerHTML == 'L') {
                document.getElementById(deposito[0]).innerHTML = 'VI'
            } else if (document.getElementById(deposito[1]).innerHTML == 'L') {
                document.getElementById(deposito[1]).innerHTML = 'VI'
            }
        }

     }, (j*1000) + 17850 );

     setTimeout(function(){ 
        document.getElementById(celulas[j].endereco).innerHTML = ''
     }, (j*1050) + 17850 );
}





// const analisaMatriz = () => {
//     // pega a tabela pelo id
//     let table = document.getElementById('matriz')

//     let matriz = []

//     // percorre celula / coluna
//     for (var i = 0, row; row = table.rows[i]; i++) {
//         let linha = []
//         //iterate through rows
//         //rows would be accessed using the "row" variable assigned in the for loop
//         for (var j = 0, col; col = row.cells[j]; j++) {
//             linha[col.id] = { pago: null }
//             //   console.log(col.id,col.innerHTML)
//             //   console.log(col.innerHTML)
//         }
//         matriz.push(linha)
//     }
//     return matriz[0]
// }

// const agenteFiscal = (posicao, matriz) => {
//     const nomeAgente = 'F'

//     let celula = matriz[posicao]
//     let posicaoAtual = posicao

//     for (let i = 0; i < 2; i++) {
//         document.getElementById(posicaoAtual).innerHTML = 'F'
        
//         if (document.getElementById(posicaoAtual).innerHTML == 'V') { // veículo não verificado
//             document.getElementById(posicaoAtual).innerHTML = 'VF'// marcar célula com 'VF'

//             if (celula.pago === false) { // veículo irregular
//                 console.log('veículo irregular')
//                 document.getElementById(posicaoAtual).innerHTML = 'VIF'
//                 //move
//                 document.getElementById(posicaoAtual).innerHTML = 'VI'
//             }
//             else {
//                 console.log('move') // funcao para mover o agente    
//             }
//         }
//         else {
//             console.log('move') // funcao para mover o agente    
//         }

//     }
// }

// document.getElementById('1.1').innerHTML = 'L'
// // document.getElementById('2.0').innerHTML = 'F'

// let matriz = analisaMatriz()

// matriz['1.1'] = { pago: false }

// agenteFiscal('2.0', matriz)

// const moverAgenteFiscal = (posicao, matriz) => {
//     cima = (parseFloat(posicao) - 1).toFixed(1)
//     var posAtual = posicao

//     console.log(document.getElementById(cima).innerHTML)

//     for (let index = 0; index < 3; index++) {
//         if (document.getElementById(cima).innerHTML === 'V') {
//             console.log('veiculo')
//             document.getElementById(cima).innerHTML = 'VF'
//             document.getElementById(posAtual).innerHTML = ''
//         } else {
//             direita = (parseFloat(posAtual) + 0.1).toFixed(1)
//             setTimeout(function(){ document.getElementById(direita).innerHTML = 'F' }, 1000);
//             // setTimeout(document.getElementById(direita).innerHTML = 'F', 1000)
//             cima = (parseFloat(direita) - 1).toFixed(1)
//             setTimeout(function(){ document.getElementById(posAtual).innerHTML = '' }, 2000);
            
//             posAtual = direita
//         }
//     }
// }

// console.log(moverAgenteFiscal('2.0', matriz))