package collections
//matriz é um array de array { {1,2,3}, {4,5,6}, {7,8,9}}
fun main() {
    //array é uma estrutura fixa
    val matriz = Array(3){ arrayOfNulls<Int>(3)}

    matriz[0][0] = 1
    matriz[0][1] = 2
    matriz[0][2] = 3
    matriz[1][0] = 4
    matriz[1][1] = 5
    matriz[1][2] = 6
    matriz[2][0] = 7
    matriz[2][1] = 8
    matriz[2][2] = 9
    //matriz.get(2).set(2,9)
    for ((linha, linhaArray) in matriz.withIndex())
        for((coluna, valor) in linhaArray.withIndex()){
            println("[$linha][$coluna] - ${matriz[linha][coluna]} == $valor")
        }

    matriz.forEach {
        it.forEach {
            println(it)
        }
    }

    matriz.forEach { linha ->
        linha.forEach { valor ->
            println(valor)
        }
    }
}