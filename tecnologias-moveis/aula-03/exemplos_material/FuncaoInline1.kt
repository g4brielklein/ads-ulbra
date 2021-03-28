package Aula3

inline fun transacao (funcao: ()->Unit){
    println("Abrindo a Transacao")
    try{
        funcao()
    } finally {
        println("Fechando a Transação")
    }
}

fun main() {
    transacao {
        println("Executando um SQL 1...")
        println("Executando um SQL 2...")
        println("Executando um SQL 3...")
    }
}