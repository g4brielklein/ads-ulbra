package classes

class Cliente{
    //membros da class = atributos + comportamentos
    var nome: String = ""
}

fun main() {
    //chamando um método construtor -> mesmo nome da classe
    val cliente = Cliente() //instanciando um objeto
    cliente.nome = "João"
    println("O cliente é ${cliente.nome}")

    val cliente1 = Cliente() //instanciando um objeto
    cliente1.nome = "Maria"
    println("O cliente é ${cliente1.nome}")

    println("Meus clientes são: ${cliente.nome} e ${cliente1.nome}")


}