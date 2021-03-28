package Aula3

fun <E> filtrar(lista: List<E>, filtro:(E)->Boolean): List<E>{
    val listaFiltrada = ArrayList<E>()
    for(e in lista){
        if(filtro(e)){
            listaFiltrada.add(e)
        }
    }
    return listaFiltrada
}

fun comTresLetras(nome:String):Boolean{
    return nome.length == 3
}

fun comSeisLetras(nome:String):Boolean{
    return nome.length == 6
}

fun main() {
    val nomes = listOf("Ana", "Carlos", "Bia", "Gui", "Rebeca")
    println(filtrar(nomes, ::comTresLetras))
    println(filtrar(nomes, ::comSeisLetras))
}