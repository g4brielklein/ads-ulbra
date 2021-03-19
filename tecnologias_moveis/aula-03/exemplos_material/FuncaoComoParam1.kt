package Aula3

class Operacoes{
    fun somar(a: Int, b: Int): Int{
        return a + b
    }
}
fun somar(a: Int, b: Int): Int{
    return a + b
}
fun multip(a: Int, b: Int ): Int{
    return a * b
}
fun calc (a: Int, b: Int, funcao: (Int,Int)->Int): Int{
    return funcao(a,b)
}
fun recepcao(nome: String): String{
    return "$nome seja bem-vindo!"
}
fun despedida(nome: String): String{
    return "$nome até breve!"
}
fun mensagem (nome: String, funcao:(String)->String):String{
    return funcao(nome)
}

fun main(){
    println(calc(2,3, Operacoes()::somar))
    println(calc(3,4, ::somar))
    println(calc(5,5, ::multip))
    println(mensagem("carlos", ::recepcao))
    println(mensagem("carlos", ::despedida))
}