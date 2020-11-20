package View;

import Model.Cliente;
import Model.Pessoa;
import Model.Servico;
import Model.Usuario;

public class Main {
    public static void main(String[] args) {
        String nome = "Teste";
        System.out.println(nome);
        
        Servico servico = new Servico(1, "barba", 30);
        
        System.out.println(servico.getDescricao());        
        System.out.println(servico.getValor());
        
        Cliente cliente = new Cliente(1, "Teste", "Rua Localhost, 127", "93295510");
        System.out.println(cliente.getNome());
        
        Usuario usuario = new Usuario(1, "admin", "123");
        System.out.println(usuario.getNome());
    }
}