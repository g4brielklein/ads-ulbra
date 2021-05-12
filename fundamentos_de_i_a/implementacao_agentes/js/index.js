// define celulas das ruas por onde os agente vão percorrer
let celulas = [2.0.toFixed(1), 2.1.toFixed(1), 2.2.toFixed(1), 2.3.toFixed(1), 2.4.toFixed(1), 2.5.toFixed(1), 2.6.toFixed(1), 2.7.toFixed(1), 3.7.toFixed(1), 4.7.toFixed(1), 4.6.toFixed(1), 4.5.toFixed(1), 4.4.toFixed(1), 4.3.toFixed(1), 4.2.toFixed(1), 4.1.toFixed(1), 4.0.toFixed(1), 3.0.toFixed(1)]

// gera veículos randomicamente na matriz
const vagas = [1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 3.1, 3.2, 3.3, 3.4, 3.5, 3.6]
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

// Percorre as céulas e marca os veículos
for (let i = 0; i < celulas.length; i++) {
    
    let atual = (document.getElementById(celulas[i])).id
    let acima = ((document.getElementById(celulas[i])).id - 1).toFixed(1)

    setTimeout(function(){ 

        // marca celula atual com F
        document.getElementById(atual).innerHTML = 'F'

        // Verifica se a celula de cima é 'V'
        if (document.getElementById(acima).innerHTML == 'V') {
            let veiculo = document.getElementById(acima)
            if (veiculo.pago == true) {
                veiculo.innerHTML = 'VR'
            }
        
            if (veiculo.pago == false) {
                veiculo.innerHTML = 'VI'
            }
        }

     }, i*1000);

     setTimeout(function(){ 
        document.getElementById(atual).innerHTML = ''
     }, i*1050);
}

for (let j = 0; j < celulas.length; j++) {
    
    let atual = (document.getElementById(celulas[j])).id
    let acima = ((document.getElementById(celulas[j])).id - 1).toFixed(1)

    setTimeout(function(){ 

        // marca celula atual com F
        document.getElementById(atual).innerHTML = 'G'

        // Verifica se a celula de cima é 'VI'
        if (document.getElementById(acima).innerHTML == 'VI') {
            document.getElementById(acima).innerHTML = 'L'
            document.getElementById(atual).innerHTML = 'GVI'
            for (x = j; x < celulas.length; x++) {
                let atualX = (document.getElementById(celulas[x])).id
                let acimaX = ((document.getElementById(celulas[x])).id - 1).toFixed(1)
                
                setTimeout(function(){ 
                
                    document.getElementById(atualX).innerHTML = 'GVI'

                }, (x*1000) + (j*1000) + 17850 );
            }
        }
    }, (j*1000) + 17850 );

    setTimeout(function(){ 
        document.getElementById(atual).innerHTML = ''
    }, (j*1050) + 17850 );
}