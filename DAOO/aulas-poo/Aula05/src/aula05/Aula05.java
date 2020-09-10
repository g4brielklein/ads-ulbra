package aula05;
public class Aula05 {
    public static void main(String[] args) {
        ContaBanco c1 = new ContaBanco();
        c1.abrirConta();
        c1.setTipo("cp");
        c1.setDono("Gabriel Klein");
        c1.setNumConta(1);
        c1.pagarMensal();
        c1.depositar(40);
        c1.sacar(10);
        c1.sacar(160);
        c1.fecharConta();
        c1.status();
    }
}
