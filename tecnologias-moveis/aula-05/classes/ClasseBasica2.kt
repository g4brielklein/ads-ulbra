package classes
//dentro dos parênteses pode-se definir um construtor diferente do padrão
//construtor tem o mesmo nome da classe
//por padrão toda classe tem o construtor padrão
class Pessoa1(var nome: String)//usando variável - nome visível por padrão
class Pessoa2(val nome: String)//usando constante - nome não vai poder alterar
//não vai gerar um atributo visível nas instâncias dos objetos (variável local)
//disponível apenas no processo de inicialização do objeto e não estará disponível
//qnd o objeto for instanciado
class Pessoa3(nomeInicial: String){ //sem var e val
    val nome: String = nomeInicial
}

fun main() {
    val p1 =Pessoa1(nome = "João")
    p1.nome = "Guilherme"
    println("${p1.nome} sabe programar")

    val p2 = Pessoa2("Maria")
    //erro nome é constante
    //p2.nome = "Guilerme"
    val p3 = Pessoa3(nomeInicial = "Pedro")
    //erro somente usado no procecsso de inicialização
    //p3.nomeInicial = "Paulo"
    println("${p2.nome} e ${p3.nome} são legais")
    val p4 = Pessoa3("Carlos")
    println("${p2.nome} e ${p4.nome} são legais")
}