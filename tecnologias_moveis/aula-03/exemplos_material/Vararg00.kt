package Aula3

fun mediav (vararg notas: Float){
    if (notas.isNotEmpty()){
        var soma = 0f
        for(nota in notas){
            soma += nota
        }
        println("A média é: ${soma/notas.size}")
    }
}

fun main() {
    mediav(8f, 8f, 8f)
    mediav(9f, 9f, 9f, 9f)
}