package oo.heranca

//classe herda de apenas de um única classe
//classe pode herdar de multíplas interfaces
//por exemplo: interface luxo (aquecimento nos bancos, som )
class Ferrari : Carro(velocidadeMaxima = 350), Esportivo{//chamada ao construtor de carro para alterar ->350
    //obrigado a  inicializar o valor de turbo
    override var turbo: Boolean = false//precisa definir a variável turbo da interface
        get() = field
        set(value) {field =value}//implementação padrão

    override fun acelerar() {
        super.alterarVelocidadeEm(if(turbo) 50 else 25)
        //se turbo estiver ligado 50
        //senão 25
    }

    override fun frear() {
        alterarVelocidadeEm(-25)
        //não é obrigado a colocar o super, pois está sendo herdado
    }

}
