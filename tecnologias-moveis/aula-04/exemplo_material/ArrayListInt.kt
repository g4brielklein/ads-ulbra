package collections

fun main() {
    val pares = arrayListOf(2, 4, 6)
    val impares = intArrayOf(1, 3, 5)


    //pares.add(8)
    //impares.set(3,7)

    for(n in impares.union(pares).sorted()){
        print("$n ")
    }
}