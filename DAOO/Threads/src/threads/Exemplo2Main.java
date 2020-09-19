package threads;
public class Exemplo2Main {
    public static void main(String[] args) {
        Exemplo2 ex2 = new Exemplo2("Thread Ex2");
        ex2.start();
        System.out.println("Thread em execucao = " + Thread.currentThread().getName());
    }
}
