package aula_03

fun potencial (base: Int = 2, expoente: Int = 1): Int {
    return Math.pow(base.toDouble(), expoente.toDouble()).toInt()
}

fun main() {
    println(potencial(8, 2))
    println(potencial(expoente = 5))
    println(potencial(expoente = 5))
    println(potencial(base = 5))
    println(potencial(expoente = 2, base = 10))
}