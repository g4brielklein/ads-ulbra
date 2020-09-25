
public class Escrita4 implements Runnable
{
    private int id;
    private static int cont=0;
    public void run(){
        for(int i=0;i<10;i++){
            System.out.println("Numero: ("+id+"):"+i);
        try{
            Thread.sleep(500);
        }
        catch(InterruptedException e){}
        }
    }
    public Escrita4(){
        cont++;
        id=cont;
    }
}
