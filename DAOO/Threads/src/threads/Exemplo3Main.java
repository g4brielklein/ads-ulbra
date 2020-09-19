package threads;
public class Exemplo3Main {
    public static void main(String[] args) {
        Exemplo3 ex3 = new Exemplo3();
        Thread t = new Thread(ex3, "Thread Ex3");
        t.start();
        System.out.println("Thread em execucao = " + Thread.currentThread().getName());
    }
}
