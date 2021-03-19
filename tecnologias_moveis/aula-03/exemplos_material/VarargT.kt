package Aula3

fun <Z> mediavt(vararg valores: Z){
    for(valor in valores){
        println(valor)
    }
}

fun main() {
    mediavt(1, 4f, "Carlos", false, 'x')
}