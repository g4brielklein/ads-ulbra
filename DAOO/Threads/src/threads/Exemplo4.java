package threads;
public class Exemplo4 implements Runnable {
    public void run() {
        for (int i = 1; i < 4; i++) {
            System.out.println("Thread " + Thread.currentThread().getName());
        }
    }
}
