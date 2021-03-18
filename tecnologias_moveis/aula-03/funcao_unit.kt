package aula_03

fun imprimeMaior(a: Int, b: Int) {
    println(Math.max(a, b))
}

fun imprimeMaior2(a: Int, b: Int): Unit {
    println(Math.max(a, b))
}

fun imprimeMaior3(a: Int, b: Int) {
    println(Math.max(a, b))
    return
}

fun imprimeMaior4(a: Int, b: Int): Unit {
    println(Math.max(a, b))
    return Unit
}

fun imprimeMaior5(a: Int, b: Int) {
    println(Math.max(a, b))
    return Unit
}

fun main() {
    imprimeMaior(8, 7)
    imprimeMaior2(8, 7)
    imprimeMaior3(8, 7)
    imprimeMaior4(8, 7)
    imprimeMaior5(8, 7)
}