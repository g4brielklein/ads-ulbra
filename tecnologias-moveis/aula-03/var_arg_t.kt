package aula_03

fun <T> mediav(vararg valores: T) {
    for (valor in valores) {
        println(valor)
    }
}

fun main() {
    mediav("Gabriel" , 2, 4.2f, false, 'X')
}