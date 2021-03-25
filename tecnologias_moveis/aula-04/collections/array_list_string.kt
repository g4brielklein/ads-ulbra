package collections

fun main() {
    // Cria array usando funções utilitárias (top level)
    val strings = arrayListOf("Carro", "barco", "Avião", "Moto")

    // Adiciona novo item ao arraylist
    strings.add("Patinete")

    // Percorre o arraylist mostrando os itens em uppercase
    for (item in strings) {
        println(item.toUpperCase())
    }
    
    for (item in strings) {
        println(item.toLowerCase())
    }
    
}
