package collections

import com.sun.org.apache.xml.internal.security.Init
import com.sun.xml.internal.fastinfoset.util.StringArray

fun main() {
    //<Int> notação do generics
    //<Int> amarrando no tipo de elementos
    //chamada de um construtor precisa dos parênteses (  )
    // (10)  tamanho
    // inicializar a partir de um lambda
    // i -> índice, vai pegar o índice * 10 e associar ao elemento do array
    // ou val numeros = Array<Int>(10, {i -> i * 10 })
    val numeros = Array<Int>(10){i -> i * 10 }

    for(numero in numeros){
        println(numero)
    }

    val reais : FloatArray = floatArrayOf(1.1f, 2.2f,3.3f,4.4f,5.5f)
    //array de objetos
    val arrayObjetos = arrayOf("AAA",1,3.3f,'X')
    val arrayStr = arrayOf("ana","pedro","carlos")

    for(real in reais){
        println(real)
    }
    for(ao in arrayObjetos){
        println(ao)
    }
    for(astr in arrayStr){
        println(astr)
    }


    val letras = Array<Char>(5){ _ -> ' ' }
    letras[0]='a'
    letras[1]='e'
    letras[2]='i'
    letras[3]='o'
    letras[4]='u'

    for(letra in letras){
        println(letra)
    }



    //acessando além do tamanho
    //numeros.set(10, 100)
    //numeros[10] = 100


    //vendo a API do array
    println(numeros.get(2))
    println(numeros[2])
    println(numeros.size)

    numeros.set(1,1234)
    println(numeros[1])

    numeros[1] = 2345
    println(numeros[1])

    //reais[5] = 6.6f

}

