package oo.encapsulamento

private val detroDoArquivo = 1
//protected val protegioNaoSuportadoAqui =1
//só faz sentido criar dentro de uma classe
internal val dentroDoProjeto =1
//constante dentro do projeto "CursoKotlin
val publico =1 //público por padrão

private fun detroDoArquivo() = 1
//protected fun protegioNaoSuportadoAqui() =1
//só faz sentido criar dentro de uma classe
internal fun dentroDoProjeto() =1
//constante dentro do projeto "CursoKotlin
fun publico() =1 //público por padrão

//sem open, não permite herança
//grandes estruturas de hernaça, aumenta a complexidade
open class Capsula {//open -> aberta para herança
    private val dentroDoObjeto =1
    protected val vaiPorHeranca =1
    internal val dentroDoProjeto = 1
    val publico = 1

    private fun dentroDoObjeto() =1
    protected fun vaiPorHeranca() =1
    internal fun dentroDoProjeto() = 1
    fun publico() = 1
}

class CapsulaFilha : Capsula() {
    //classe filha
    fun verificarAcesso() {
        //println(Capsula().dentroDoObjeto)//não é transmitido por herança
        //println(Capsula().vaiPorHeranca)//não precisa instanciar, vem por herança
        println(vaiPorHeranca)
        println(dentroDoProjeto)
        println(publico)
    }
}
fun verificarAcesso(){// função toplevel
   // println(Capsula().dentroDoObjeto())//tem que instanciar, fora da classe
   // println(Capsula().vaiPorHeranca())//só transmitido por herança
    println(Capsula().dentroDoProjeto())
    println(Capsula().publico())
}
