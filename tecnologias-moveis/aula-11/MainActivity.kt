package com.aula.gastodeviagem

import android.app.Activity
import android.os.Bundle
import android.widget.*

class MainActivity() : Activity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        // Definindo o arquivo de layout
        setContentView(R.layout.activity_main)

        // Acessando a caixa de distancia
        val txt_distancia = findViewById<EditText>(R.id.txt_distancia)

        // Acessando a caixa de preco
        val txt_preco = findViewById<EditText>(R.id.txt_preco)

        // Acessando a caixa de autonomia
        val txt_autonomia = findViewById<EditText>(R.id.txt_autonomia)

        // Acessando o botão de calcular
        val btn_calcular = findViewById<Button>(R.id.btn_calcular)

        // Acessando o texto de resultado
        val txt_texto_resultado = findViewById<TextView>(R.id.txt_texto_resultado)
        txt_texto_resultado.text = "Seu gasto total será de:"

        // Acessando o resultado
        val txt_resultado = findViewById<TextView>(R.id.txt_resultado)

        // Acessando as notificacoes
        val txt_notificacoes = findViewById<TextView>(R.id.txt_notificacoes)

        btn_calcular.setOnClickListener {


            // Capturando a distancia selecionado
            val distancia = txt_distancia.text.toString().toDouble()

            // Capturando o preco digitado
            val preco = txt_preco.text.toString().toDouble()

            // Capturando a autonomia digitada
            val autonomia = txt_autonomia.text.toString().toDouble()


//            if (distancia.toString().equals("")) {
            if (distancia.toString() == "0.0"
                || preco.toString() == "0.0"
                || autonomia.toString() == "0.0"
            ) {
                txt_notificacoes.text = "Preencha os campos!"
            } else {
                txt_notificacoes.text = ""
            }


            // Variável para guardar o resultado do cálculo
            var resultado = (distancia * preco) / autonomia

            // Atualizando a tela de acordo com o resultado do cálculo
            txt_resultado.text = "R$ $resultado"

        } // btn

    } // override

} // class