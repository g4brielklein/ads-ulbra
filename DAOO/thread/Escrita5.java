
public class Escrita5 extends Thread
{
    Escrita5(String id){
        super(id);
    }
    Escrita5(String id, int prioridade){
        super(id);
        setPriority(prioridade);
    }
    public void run(){
        for(int i=0;i<10;i++){
            System.out.println(getName()+i);
            yield();
        }
    }
}
