
public class Escrita3 implements Runnable
{
    private int id;
    private static int cont=0;
        public void run(){
         for(int i=0;i<10;i++){
            System.out.println("Numero: ("+id+"):"+i);
         }
        }
        public Escrita3(){
            cont++;
            id=cont;
        }
}
