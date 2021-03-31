package collections

fun main() {
    val aprovados = hashSetOf("João", "Maria", "Pedro", "Ana", "Joana")
    //uma ve que criou com String, é um conunto de Strings
    //aprovados.add(1)

    println("Sem ordem...")
    for(aprovado in aprovados){
        aprovado.print()
    }
    println("Ordenado1...")
    val aprovadosNaOrdem1 = linkedSetOf("João", "Maria", "Pedro", "Ana", "Joana")
    for(aprovado in aprovadosNaOrdem1){
        aprovado.print()
    }
    println("Sorted...")
    val aprovadosNaOrdem2 = sortedSetOf("João", "Maria", "Pedro", "Ana", "Joana")
    for(aprovado in aprovadosNaOrdem2){
        aprovado.print()
    }
    println("ordenado por critério seu...")
    //usando a orndenação a partir da segunda letra
    aprovados.sortedBy { it.substring(1) }.print()
}