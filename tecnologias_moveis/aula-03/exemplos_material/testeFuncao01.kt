package Aula3

fun endereco(rua: String = "", cidade: String, estado: String, cep:String, numero: Int = 0){
    println("Rua = $rua, $numero")
    println("Cidade: $cidade,$estado,$cep")
}

fun main() {
    endereco("Rua X","POA","RS","90000", 1011)
    //endereco(cep = "90000-900", cidade = "Santa Maria", estado = "RS")
}