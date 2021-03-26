package collections
//Any é superclasse dos tipos básico
//criadno o métiodo print
//colocando o método println dentro da classe Any

fun Any.print() = println(this)

fun main(){
    val conjunto = hashSetOf( 3, 'a', "texto", true, 3.14)

    //conjunto.set(1)
    // o set não aceita repetição
    //conjunto.add(3).print()
    conjunto.add(10).print()//não está contido no conjunto

    conjunto.size.print()

    conjunto.remove("a").print()
    conjunto.remove('a').print()

    conjunto.contains('a').print()
    conjunto.contains("Texto").print()
    conjunto.contains("texto").print()

    val nums = setOf(1,2,3)//somemte leitura
    //nums.add(4)

    (conjunto + nums).print()
    (conjunto - nums).print()

    conjunto.intersect(nums).print() //intersecção, não altera
    conjunto.retainAll(nums)// muda o conjunto
    conjunto.print()// ficou só o 3

    conjunto.clear()
    conjunto.isEmpty().print()
}