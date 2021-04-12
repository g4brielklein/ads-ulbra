package classes
/* Erro!! Kotlin: val can not be reassigned
fun porReferencia(velocidade: Int){
    velocidade++; //vai dar erro
}*/
//3 variáveis -> var
//se mudar velocidade para val, vai dar erro
data class Carro(var marca: String, var modelo: String , var velocidade: Int = 0)

fun porReferencia(carro:Carro){//recebendo carro
    carro.velocidade++//velocidade pode ser alterada sem problema
    //velocidade é var
}

fun main() {
    var carro1 = Carro("Ford", "Fusion")

    var carro2 = carro1// recebe a referência de carro1
    //aponta para a mesma referência de carro1

    carro2.modelo ="Edge"
    println(carro1)//vai mostrar alterado, mesma referência

    carro1 = Carro("Audi", "A4")//nova referência pra carro1
    carro2.velocidade = 2

    porReferencia(carro1)//incrementou velocidade
    porReferencia(carro2)

    println(carro1)//velocidade incrementada nos dois
    println(carro2)

    var a = 1//tipos básico em Kotlin são objetos
    var b = a
    println(a === b)//são objetos vai dar true
    b++//é criada uma nova referência pra b
    println(a === b)
    println(a)
    println(b)
    //nos dados criados pelo usuário o comportamento é outro
    //alguns tipos de operações alteram a referência

}
