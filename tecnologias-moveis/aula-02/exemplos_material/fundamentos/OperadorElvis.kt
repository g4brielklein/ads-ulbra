package fundamentos

fun main() {
    val opcional: String? = null//safe call operator
   // val obrigatorio: String = opcional // opcional pode não ter valor, não tem "?"
    val obrigatorio: String = opcional ?:"Valor Padrão"
    println(obrigatorio)
}