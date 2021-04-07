package oo.heranca
//serve para definir métodos, sem implementar
//pode colocar apensa as assinaturas, quem herda é obrigado a definir
interface Esportivo{//permite definir apenas a assinatura
    var turbo: Boolean //não pode definir um valor
    fun ligarTurbo(){
        turbo = true
    }
    fun delisgarTurbo(){
        turbo = false
    }
}