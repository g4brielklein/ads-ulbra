package collections

fun main() {
    //criando array usando funções utilitárias (top level)
    // <string> ou <any>
    val strings = arrayListOf("Carro","Barco","Avião", "Moto")

    strings.add("Patinete")

    for(item in strings)
        println(item.toUpperCase())
}