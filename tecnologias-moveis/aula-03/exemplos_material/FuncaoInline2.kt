package Aula3

inline fun <T> executarComLog(nomeFuncao: String, funcao: ()->T): T{
    println("Entrando no método $nomeFuncao")
    try {
        return  funcao()
    } finally {
        println("Método $nomeFuncao finalizando...")
    }
}

fun somarTeste(a: Int, b: Int ): Int {
    return a + b
}

fun main() {
    val resultado = executarComLog("somar") {
        somarTeste(4, 5)
    }
    println(resultado)
}