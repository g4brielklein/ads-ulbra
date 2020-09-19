package threads;
public class Exemplo2 extends Thread {
    Exemplo2(String nomeThread) {
        super(nomeThread);
    }
    
    public void run() {
        for (int i = 0; i < 6; i++) {
            System.out.println(this.getName() + ":" + i);
        }
    }
}
