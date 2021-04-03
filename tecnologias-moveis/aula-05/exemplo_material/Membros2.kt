package classes
//encadear várias
class Calculadora {
    //private variável interna armazenar os resultado
    private var resultado: Int = 0
    //vararg -> passar uma lista de inteiros
    //resulado do método vai retornar o próprio tipo da classe que é dona da função
    fun somar (vararg valores: Int): Calculadora{//retorna um objeto do tipo calculadora
        //navegar em cada um dos valores que recebeu no vararg
        valores.forEach{ resultado += it}//it -> acessa o item corrente
        return this //retorna o objeto atual/corrente
    }
    //vai receber um único inteiro
    fun multiplicar (valor: Int): Calculadora {
        resultado *= valor// pega o valor armazenado em resultado
        return this //retorna o objeto atual/corrente
    }
    fun limpar(): Calculadora{
        resultado = 0
        return this
    }
    fun print(): Calculadora{
        println(resultado)
        return this
    }
    fun obterResultado(): Int {
        return resultado
    }
}
//objetivo fazer o encadeamento de várias chamadas em cima do objeto calculadora
//sempre que eu fizer uma chamada para uma função que retorna calculadora, você consegue
//encadear o uma outra função que também é da classe calculadora
fun main() {
    val calculadora =Calculadora()
    //criar novo objeto e testar
    calculadora.somar(1,2,3).multiplicar(3).print()
    calculadora.somar(7,10).print().limpar()//limpou por último
    calculadora.print()//mostrou limpo
    println(calculadora.obterResultado().inc())//unico método que não pode ser encadeado.
    //já pode chamar os métodos do inteiro

}