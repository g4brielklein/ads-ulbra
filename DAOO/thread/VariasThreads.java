
public class VariasThreads
{
    public static void main(String args[]){
        Runnable r1 = new Escrita3();
        Runnable r2 = new Escrita3();
        Thread t1 = new Thread(r1);
        Thread t2 = new Thread(r2);
        t1.start();
        t2.start();
    }
}
