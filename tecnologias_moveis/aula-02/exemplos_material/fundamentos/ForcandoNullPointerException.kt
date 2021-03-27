package fundamentos

fun main() {
    var a: Int? = null //pode estar nulo
    println(a?.inc())//chamada segura

    println("Agora o erro....")
    println(a!!.inc())// "!!" forçar a chamada
}