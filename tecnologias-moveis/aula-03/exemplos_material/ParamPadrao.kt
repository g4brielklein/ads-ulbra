package Aula3

fun potencia( base: Int = 2, expoente: Int = 1): Int{
    return Math.pow(base.toDouble(),expoente.toDouble()).toInt()
}

fun main() {
    println(potencia(2,3))
    println(potencia(10))
    println(potencia(expoente = 5))
    println(potencia(base = 5))
    println(potencia(expoente = 3, base = 3))
}

