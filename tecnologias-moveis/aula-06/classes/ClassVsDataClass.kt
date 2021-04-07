package classes

class Geladeira(val marca: String, val litros: Int)
data class Televisao(val marca: String, val polegadas: Int)

fun main() {
    val g1 = Geladeira("Brastemp", 320)
    val g2 = Geladeira("Brastemp", 320)

    //comparar o == internamente ele chama o equals
    //mas não é um data class, não implemente o equals
    //println(g1==g2)// resultado false comparou referência de memória
    println(g1.marca == g2.marca)

    //automaticamente compara todos os atributos
    //utiliza o equals
    val tv1 = Televisao("Samsung", 42)
    val tv2 = Televisao("Samsung", 42)

    println(tv1==tv2)//comparou todos os atributos

    println(tv1===tv2)//comparando referência

    println(tv1.toString())//mostra os atributos
    println(tv1.copy(polegadas=42))//dá uma cópia do objeto baseado em val "constantes"
    //geraria uma nova cópia alterando os atributos que desejaria

    //Destructuring em data class
    val (marca, pol) = tv1
    println("$marca $pol")

    //val (marca, pol) = g1 //vai dar erro não é data class
    //println("$marca $pol")


}