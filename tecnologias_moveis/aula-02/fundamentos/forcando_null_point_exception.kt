package fundamentos

fun main() {
    var a: Int? = null
    println(a?.inc())

    println("Agora o erro...")
    println(a!!.inc())
}