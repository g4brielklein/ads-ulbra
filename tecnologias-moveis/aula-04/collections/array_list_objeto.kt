package collections

data class Fruta (var nome: String, var preco: Double)

fun main() {
    var frutas = arrayListOf(Fruta("Banana", 1.5), Fruta("Maça", 1.99))

    for (fruta in frutas) {
        println("${fruta.nome} - R$ ${fruta.preco}")
    }

    println(frutas.contains(Fruta("Maça", 1.98)))
    println(frutas.contains(Fruta("Maça", 1.99)))
    println(frutas.distinctBy{ it.preco })
}