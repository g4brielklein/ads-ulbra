package aula05;
public class ContaBanco {
    public int numConta;
    protected String tipo;
    private String dono;
    private float saldo;
    private boolean status;
    
    public ContaBanco() {
        this.status = false;
        this.saldo = 0;
    }
    
    public void abrirConta() {
        this.setStatus(true);
    }
    
    public void fecharConta() {
        if (this.saldo == 0) {
            this.setStatus(false);
        } else {
            System.out.println("O saldo da conta está diferente de zero.");
        }
    }
    
    public void depositar(float d) {
        if (this.status == true) {
            this.saldo = this.saldo + d;
        }
    }
    
    public void sacar(float s) {
        if (this.status == true && this.saldo >= s) {
            this.saldo = this.saldo - s;
        }
    }
    
    public void pagarMensal() {
        if (this.tipo == "cc") {
            this.saldo = this.saldo - 12;
        } else {
            if (this.tipo == "cp") {
                this.saldo = this.saldo - 20;
            }
        }
    }
    
    public int getNumConta() {
        return this.numConta;
    }
    
    public void setNumConta(int n) {
        this.numConta = n;
    }
    
    public String getTipo() {
        return tipo;
    }
    
    public void setTipo(String t) {
        this.tipo = t;
        if (this.tipo == "cc") {
            this.setSaldo(50f);
        } else {
            if (this.tipo == "cp") {
                this.setSaldo(150);
            }
        }
    }

    public String getDono() {
        return dono;
    }
    
    public void setDono(String d) {
        this.dono = d;
    }
    
    public float getSaldo() {
        return saldo;
    }
    
    public void setSaldo(float s) {
        this.saldo = s;
    }
    
    public boolean getStatus() {
        return status;
    }
    
    public void setStatus(boolean s) {
        this.status = s;
    }
    
    public void status() {
        System.out.println("Informações da conta: ");
        System.out.println("Número da conta: " + getNumConta());
        System.out.println("Tipo da conta: " + getTipo());
        System.out.println("Dono da conta: " + getDono());
        System.out.println("Saldo da conta: " + getSaldo());
        System.out.println("Está ativa? " + getStatus());
    }
}
