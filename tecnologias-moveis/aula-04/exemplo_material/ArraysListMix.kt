package collections

fun main() {
    val listaMix = arrayListOf("Carlos", true, 1, 3.14,'p', "Ana")

    listaMix.add(false)

    for (item in listaMix){
        if(item is String){
            println(item.toUpperCase())
        }else{
            println(item)
        }
    }
}