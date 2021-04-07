package oo.heranca

fun main() {
    val carro = Ferrari()
    carro.acelerar()
    println("A velocidade atual é ${carro.velocidadeAtual} Km/h")

    carro.ligarTurbo()

    carro.acelerar()

    println("A velocidade atual é ${carro.velocidadeAtual} Km/h")

    carro.frear()
    carro.frear()
    println("A velocidade atual é ${carro.velocidadeAtual} Km/h")

}