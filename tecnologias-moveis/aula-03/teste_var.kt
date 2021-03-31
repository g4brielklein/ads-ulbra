package aula_03

fun ola(nome: String) {
    println("${nome} este é um exemplo de função")
}

fun adicao(a: Int, b: Int) = a + b

fun main() {
    ola("Gabriel")
    val a = 10
    val b = 20
    println(adicao(a, b))
}