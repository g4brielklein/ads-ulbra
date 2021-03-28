package aula_03

fun main() {
    try {
        println("teste".toInt())
        } catch (e: NumberFormatException) {
            println("Esse valor não é um número")
        } catch (e: Exception) {
        println("Algo de errado aconteceu!")
        } finally {
            println("Exceção tratada.")
        }
}