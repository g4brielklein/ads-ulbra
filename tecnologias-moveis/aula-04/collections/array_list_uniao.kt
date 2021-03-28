package collections

fun main() {
    val numeros = arrayListOf(1, 2, 3, 4, 5)
    val strings = arrayListOf("Gabriel", "Sabrina", "Marcia", "Beto")

    val uniao = strings + numeros

    for (item in numeros.union(strings)) {
        println(item)
    }
}

