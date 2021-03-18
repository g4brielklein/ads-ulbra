package aula_03

fun endereco(rua: String = "", cidade: String, estado: String, cep: String, numero: Int = 0) {
    println("Rua = $rua")
    println("Cidade =  $cidade, $estado, $cep")
}

fun main() {
//    endereco("Rua X", "POA", "RS", "99999999")
    endereco(cep = "90000-900", cidade = "Sapucaia do Sul", estado = "RS")
}