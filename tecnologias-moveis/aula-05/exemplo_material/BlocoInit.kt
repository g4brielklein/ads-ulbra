package classes

//quando não usa var nem val, cria apenas os dados disponíveis na inicialização

class Filme3(nome: String, anoLancamento: Int, genero: String){
    val nome: String
    val anoLancamento: Int
    val genero: String

    //quando precisar de um tipo de inicialização mais complexa usar o init ou constructor
    init{
        this.nome = nome
        this.anoLancamento = anoLancamento
        this.genero = genero
    }
}

fun main() {
    val filme = Filme3( "Os Incríveis", 2004, "Ação")
    println("O filme do genero ${filme.genero} ${filme.nome} foi lançado em ${filme.anoLancamento}")
}