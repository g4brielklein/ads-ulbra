package classes

class Filme {
    //trabalhar sempre que possível com constantes de instância
    //quanto mais contantes forem seus dados, mais você vai ter capacidade de trabalhar com múltiplas threads
    //sem ter problema de concorrência e menos bugs você vai enfrentar porque os dados são constantes
    //então não geram efeitos colaterais
    //variáveis sempre com escopo mais restrito
    val nome: String
    val anoLancamento: Int
    val genero: String
    //vai dar erro antes de delcarar o constructor
    //não pode declarar uma constante sem inicializar

    //não usa o mesmo nome da classe na declaração
    //não tem mais acesso ao construtor padrão
    constructor(nome: String, anoLancamento: Int, genero: String){
        this.nome = nome//mesmo nome do parâmetro é o mesmo nome da constante de instância usa o this
        this.anoLancamento = anoLancamento//this objeto corrente
        this.genero = genero
    }
}

fun main() {
    val filme = Filme("o Podereso Chefão", 1972, "Drama")
    println("O ${filme.genero} ${filme.nome} foi lançado em ${filme.anoLancamento}")
}