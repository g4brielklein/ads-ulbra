package trabalhoaula05;

import java.util.ArrayList;

public class Mesa {
    private int numero;
    private String cliente;
    private String pedido;
    private float valor;

    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public String getCliente() {
        return cliente;
    }

    public void setCliente(String cliente) {
        this.cliente = cliente;
    }

    public String getPedido() {
        return pedido;
    }

    public void setPedido(String pedido) {
        this.pedido = pedido;
    }

    public float getValor() {
        return valor;
    }

    public void setValor(float valor) {
        this.valor = valor;
    }
    
    
    
    public void status() {
        System.out.println("Dados da mesa: ");
        System.out.println("Numero: " + getNumero());
        System.out.println("Cliente: " + getCliente());
    }
}
