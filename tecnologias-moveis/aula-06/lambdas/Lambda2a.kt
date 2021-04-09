package lambdas

class Calculadora1{
    fun calcular(a: Int, b: Int): Int{
        return a + b
    }
    // o terceiro parâmetro é uma expressão lambda
    // operação vai ser do tipo lambada, definindo o lambada recebe 2 Int e retorna 1 Int
    fun calcular(a: Int , b:Int, operacao:(Int,Int) -> Int):Int {
        return operacao(a,b)//chamar a função lambda
    }
}

fun main(){
    val calculadora = Calculadora1()

    val subtracao = {a: Int, b: Int -> a -b}//criar uma função lambda e definir o corpo

    val resultado1 = calculadora.calcular( 3,4)
    val resultado2 = calculadora.calcular(3,4, subtracao)

    println("$resultado1 $resultado2")
}