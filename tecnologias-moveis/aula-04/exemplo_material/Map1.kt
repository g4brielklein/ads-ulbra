package collections
// par = ( chave (set), valor (list) )
// (keys=values)
//chave não pode ter repetição
//valor pode harve repetição
//put usado para inserir e alterar a partir da mesma chave
fun main() {
    var map = HashMap<Long,String>()//construtor do map

    map.put(10020030040, "João")
    map.put(30040050040, "Maria")
    map.put(40050060040, "Pedro")

    for(par in map){
        println(par)
    }

    map.put(40050060040, "Pedro Filho")

    for(par in map.entries){
        println(par)
    }

    for(nome in map.values){
        println(nome)
    }

    for(cpf in map.keys){
        println(cpf)
    }
    //DESESTTRUTURANDO (cpf,nome)
    for ((cpf,nome) in map){
        println ("$nome (CPF: $cpf)")
    }

    map.size.print()
    map.get(30040050040)?.print()// safe call pq pode ser nulo
    map[30040050040]?.print()
    map.contains(30040050040).print()//true ou false
    map.remove(30040050040)?.print()
    map.clear()
    map.isEmpty().print()
}