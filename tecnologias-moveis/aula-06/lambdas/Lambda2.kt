package lambdas

//por padrão a funçaõ calcular soma
//depois com lambda passr a função da operação
interface Operacao{
    fun executar (a: Int, b: Int):Int
}

class Multiplicacao: Operacao{
    override fun executar(a: Int, b: Int): Int {
        return a * b
    }
}

class Calculadora{
    fun calcular(a: Int,b: Int):Int{
        return a + b
    }

    fun calcular(a: Int, b: Int, operacao:Operacao): Int {
        return operacao.executar(a,b)
    }

}

fun main(){
    val calculadora = Calculadora()
    val resultado1 = calculadora.calcular(3,4)
    val resultado2 = calculadora.calcular(3,4, Multiplicacao())


    println("$resultado1 $resultado2")
}