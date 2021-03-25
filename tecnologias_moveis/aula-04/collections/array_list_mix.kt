package collections

fun main() {
    val lista_mix = arrayListOf("Gabriel", true, 1, 3.14, 'p')

    lista_mix.add(false)

    for (item in lista_mix) {
        if (item is String) {
            println(item.toUpperCase())
        } else {
            println(item)
        }
    }
}