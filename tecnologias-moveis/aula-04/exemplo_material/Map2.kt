package collections
//métodos utilitários hashMapog
fun main() {
    val map = hashMapOf(1 to "Gui", 2 to "Rebetáriosca", 3 to "Paulo", 4 to "Ana")
    for ((id,nome) in map){
        println("$id - $nome")
    }
}