package fundamentos

import fundamentos.pacoteA.simples_funcao as funcao_simples
import fundamentos.pacoteA.Coisa
import fundamentos.pacoteA.face_moeda.cara
import fundamentos.pacoteB.*

fun main() {
    val coisa = Coisa("Bola")
    println(coisa.nome)

    println(cara)

    println("${soma(2, 3)} ${subtracao(4, 6)}")
}