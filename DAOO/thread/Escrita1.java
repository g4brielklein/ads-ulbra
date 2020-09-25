
public class Escrita1 extends Thread
{
    private int id;
    public void run(){
        for(int i=0;i<10;i++){
            System.out.println("Numero: "+i);
        }
    }
   
}
