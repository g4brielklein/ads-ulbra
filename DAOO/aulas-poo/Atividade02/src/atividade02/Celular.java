package atividade02;
public class Celular {
    String marca;
    String cor;
    int armazenamento;
    boolean ligado;
    
    void ligar() {
        this.ligado = true;
    }
    
    void desligar() {
        this.ligado = false;
    }
    
    void telefonar() {
        if (this.ligado == true) {
            System.out.println("Estou telefonando");
        } else {
            System.out.println("ERRO! Não posso telefonar");
        }
    }
}
