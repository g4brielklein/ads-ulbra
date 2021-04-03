package classes

val diretamenteNoArquivo = "Bom dia"

fun topLevel(){
    val local = "Fulano!"
    println("$diretamenteNoArquivo $local")
}
class Coisa {
    var variavelDeInstancia: String = "Boa Noite"

    //99% das vezes as funcionalidades static são definidas por topLevel
    //quando for gerado o bytecode gera no Java uma constante static
    //se tirar o @ não será mais constante statica será um membro de companion object
    //terá um comportamento diferente
    companion object{//membros static soemnte dentro do companion
        //declarando uma constante static
        @JvmStatic val constanteDeClasse = "Ciclano"
    }

    fun fazer() {
        val local: Int = 7 //em funções diferentes c/escopos diferentes
        if(local>3){
            val variavelDeBloco = "Beltrano" //variável de bloco
            println("$variavelDeInstancia, $constanteDeClasse, $local e $variavelDeBloco")
        }
    }
}

fun main() {
    topLevel()
    //var CC = Coisa()
    //CC.fazer()
    Coisa().fazer()
    //chamar uma constante de classe
    println(Coisa.constanteDeClasse)//não precisou criar uma instância

}