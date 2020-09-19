package threads;
public class Exemplo3 implements Runnable {
    public void run() {
        for (int i = 0; i < 6; i++) {
            System.out.println(Thread.currentThread().getName() + ":" + i);
        }
    }
}
