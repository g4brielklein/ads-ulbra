package collections

fun main() {
    val alunos = arrayListOf("Maicom", "Kauan", "Dionatam")
    for (aluno in alunos) {
        println(aluno)
    }

//    Desestruturando
    for ((indice, aluno) in alunos.withIndex()) {
        println("$indice = $aluno")
    }
}