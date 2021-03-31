package Aula3

import java.lang.Exception
import java.lang.NumberFormatException

fun main() {
 //   println("teste".toInt())
    try {
        println("100".toInt())
        } catch (e: NumberFormatException){
            println("Esse valor não é um número")
        } catch (e: Exception){
            println("Algo de errado ocorreu!")
        } finally {
            println("Exceção Tratada!")
        }
}