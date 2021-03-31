package collections

fun main() {
    val numeros = arrayListOf(1,2,3,4,5)
    val strings = arrayListOf("Carlos", "Ana", "Pedro", "Paulo")

    numeros.add(6)
    strings.add("Clara")
    strings.add(0,"Pedro")
    strings.set(0,"Márcia")

    // sobrecarga de operadores para unir dois conjuntos
    val uniao = numeros + strings

    for (item in uniao){
        println(item)
    }
}