package aula_03

fun incremento(num: Int):Int {
    var n = num
    return ++n
}

fun main() {
    println(incremento(1))
}