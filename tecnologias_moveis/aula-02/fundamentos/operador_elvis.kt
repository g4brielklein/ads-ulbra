package fundamentos

fun main() {
    val opcional: String? = null //safe call operator
    val obrigatorio: String = opcional ?:"Valor Padrão"
    println(obrigatorio)
}