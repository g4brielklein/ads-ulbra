package oo.heranca
//definir a classe mais genérica Carro
//definir os atrobutos de carro
//classe aberta para definir subclasses
open class Carro(val velocidadeMaxima: Int =200, var velocidadeAtual: Int =0) {
    //método transmitido por herança,mas ninguém pode acessar diretamente
    //atributo velocidade-> passar valor que vai ser acrescido ou subtraída da velc. atual
    protected fun alterarVelocidadeEm(velocidade: Int) {
        val novaVelociade = velocidadeAtual + velocidade
        //verificar se a novaVelocidade viola a velocidadeMaxima
        //se a novaVelocidade estiver fora do intervalo ou retorna velc máxima ou zero
        velocidadeAtual = when (novaVelociade) {
            in 0..velocidadeMaxima -> novaVelociade
            in velocidadeMaxima + 1..Int.MAX_VALUE -> velocidadeMaxima
            else -> 0//sempre usar o else
        }
    }

    open fun acelerar(){//aberto para ser sobrescrito
        alterarVelocidadeEm(5)
    }
    open fun frear(){
        alterarVelocidadeEm(-5)
    }

    //sobreecrever o toString
 /*   override fun toString(): String {
        return "A velocidade atual é $velocidadeAtual Km/h"
    }
*/
}
