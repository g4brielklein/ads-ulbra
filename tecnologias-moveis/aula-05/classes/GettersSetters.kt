package classes
//personalizaar os getters e setters
//estamos acessando os atributos sem usar o gettes e setters

class Cliente2{
    constructor(nome: String){
        this.nome = nome//cria o atributo depois do construtor
    }
    var nome: String
        //field -> atributo corrente associado
        get() = "Meu nome é ${field}" //variável field
        set(value) {//set recebe um valor
            //takeif -> lambda (coloca uma expressão true/false) que se for true o valor será retornado
            // se for false retornará nulo
            //use o ?: "elvis operator" para caso de ser vazio
            field = value.takeIf { value.isNotEmpty() } ?:"Anônimo" //se estiver vazio
        }
}

//não precisam ser implementados dezenas de métodos get e set como no Java
//só interessa se precisar sobrescrever

fun main() {
    val c1 = Cliente2("")
    println(c1.nome)

    val c2 = Cliente2("Pedro")
    println(c2.nome)
}