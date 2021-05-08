package com.example.calculoimc

import android.annotation.SuppressLint
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.Menu
import android.view.MenuItem
import com.example.calculoimc.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {
    private lateinit var binding: ActivityMainBinding
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)


        val bt_calcular = binding.btCalcula
        val mensagem = binding.textFinal

        bt_calcular.setOnClickListener {
            val peso = binding.peso.text.toString()
            val altura = binding.altura.text.toString()

            if(peso.isEmpty()){
                mensagem.setText("Informe o seu peso")
            }
            else if(altura.isEmpty()){
                mensagem.setText("Informe a sua altura")
            }
            else{
                CalculoIMC()
            }
        }
    }
    private fun CalculoIMC(){

        val peso = Integer.parseInt(binding.peso.text.toString())
        val altura = java.lang.Float.parseFloat(binding.peso.text.toString())
        val resultado = binding.textFinal
        val imc = peso/(altura*altura)

        val Mensagem = when{
            imc >= 16.0 && imc < 17.0 -> "Muito abaixo do peso"
            imc >= 17 && imc < 18.5 -> "Abaixo do peso"
            imc >= 18.5 && imc < 25.0 -> "Peso normal"
            imc >= 25 && imc < 30.0 -> "Acima do peso"
            imc >= 30.0 && imc < 35.0 -> "Obesidade grau 1"
            imc >= 35.0 && imc <= 40.0  -> "Obesidade grau 2"
            imc > 40.0 -> "Obesidade grau 3"

            else -> "Informe valores válidos"
        }
        imc.toString()
        resultado.setText("IMC: $imc \n $Mensagem")
    }

    override fun onCreateOptionsMenu(menu: Menu?): Boolean {

        val inflate = menuInflater
        inflate.inflate(R.menu.menu_principal,menu)
        return true
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {

        when(item.itemId){
            R.id.reset  ->{
                val peso = binding.peso.setText("")
                val altura = binding.altura.setText("")
                val texto = binding.textFinal.setText("")
            }
        }
        return super.onOptionsItemSelected(item)
    }
}