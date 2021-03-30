package fundamentos

fun main() {
    // safe call operator
    var a: Int? = null // '?' operador de chamada segura
    println(a?.dec())
}