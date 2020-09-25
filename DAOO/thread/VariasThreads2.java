
public class VariasThreads2
{
    public static void main(String args[]){
        Runnable r1 = new Escrita4();
        Runnable r2 = new Escrita4();
        Thread t1 = new Thread(r1);
        Thread t2 = new Thread(r2);
        t1.start();
        t2.start();
    }
}
