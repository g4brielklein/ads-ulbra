package collections

fun main() {
    val numeros = Array<Int>(10){ i -> i * 10 }
    val arrayObjetos = arrayOf("AAA",1,3.3f,'X')

    // Acessando alem do tamanho
    // numeros.set(11, 120)

    // alterando array
    numeros.set(1, 21)
    numeros[2] = 23

    println(numeros.get(1))

    // Percorrendo array
    for (objeto in arrayObjetos) {
        println(objeto)
    }

    for (numero in numeros) {
        println(numero)
    }
}