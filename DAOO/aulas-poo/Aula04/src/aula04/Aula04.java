package aula04;
public class Aula04 {
    public static void main(String[] args) {
        Caneta c1 = new Caneta("BIC", 0.5f, "Preta");
        Caneta c2 = new Caneta("Faber Castel", 1.0f, "Vermelha");
        c1.status();
        System.out.println("--------------------");
        c2.status();
    } 
}
