package Model;

import java.util.Date;

// Utilizando herança
public class Cliente extends Pessoa {
    
    private String endereco;
    private String cep;

    public Cliente(String endereco, String cep, int id, String nome, char Sexo, Date dataNascimento, String telefone, String email, String rg) {
        super(id, nome, Sexo, dataNascimento, telefone, email, rg);
        this.endereco = endereco;
        this.cep = cep;
    }

    public Cliente(int id, String nome, String endereco, String cep) {
        super(id, nome);
        this.endereco = endereco;
        this.cep = cep;
    }
    
    public String getEndereco() {
        return endereco;
    }

    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }

    public String getCep() {
        return cep;
    }

    public void setCep(String cep) {
        this.cep = cep;
    } 
}