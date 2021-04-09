package lambdas

fun main(){
    //passar funções como parâmetros
    //armazenar funções em variáveis
      val soma = {x: Int, y: Int -> x + y}//-> o que vem depois da seta é o corpo da função
/*    val soma = {x: Int, y: Int ->
        x + y
        1 + 3//sempre é o último valor que retorna
        "Texto"
    }
    */
    println(soma(4,6))
}