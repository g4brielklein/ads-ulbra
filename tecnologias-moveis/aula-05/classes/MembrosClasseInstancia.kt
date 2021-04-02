package classes
//criar uma variável de classe = static
var desconto: Double =0.0// exemplo de constante topLevel

class ItemDePedido( val nome: String, val preco: Double){
    //objeto companheiro -> tem uma instância para essa classe
    companion object{//trocar por variáveis topLevel
        //método static -> retornar um item de pedido (como se fosse um construtor)
        fun create(nome: String, preco: Double) = ItemDePedido(nome,preco)
        //@JvmStatic var desconto: Double = 0.0
    }
    fun precoComDesconto(): Double{//retorna um Double
        return preco - preco * desconto
    }
}

fun main() {
    val item1 = ItemDePedido.create("TV 50 Polegadas",2889.90)// usando create
    val item2 = ItemDePedido("liquidificador", 200.00)//usando o construtor padrão

    //ItemDePedido.desconto =0.10
    desconto = 0.10

    println(item1.precoComDesconto())

    println(item2.precoComDesconto())


}
