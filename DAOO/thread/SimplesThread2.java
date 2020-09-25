
public class SimplesThread2
{
    public static void main(String args[]){
        Escrita2 e= new Escrita2();
        Thread t= new Thread(e);
        t.start();
    }
}
