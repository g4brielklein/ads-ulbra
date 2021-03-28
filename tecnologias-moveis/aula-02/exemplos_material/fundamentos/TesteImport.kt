package fundamentos

//importar e alterar o nome
import fundamentos.pacoteA.simplesFuncao as funcaoSimples
//importar a classe Coisa
import fundamentos.pacoteA.Coisa
//importar apenas o elemento da enum
import fundamentos.pacoteA.FaceMoeda.CARA
//improtar todos os elementos do pacoteB
import fundamentos.pacoteB.*

fun main() {
    //exemplo do import padrão
    //passar um texto para a funcaoSimples
    kotlin.io.println(funcaoSimples("OK"))
    //instanciar um objeto do tipo coisa
    val coisa = Coisa("Bola")//passando o nome
    println(coisa.nome)

    println(CARA)

    println("${soma(2,3)} ${subtracao(4,6)}")
}