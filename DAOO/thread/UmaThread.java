
public class UmaThread extends Thread
{
    private int delay;
    public UmaThread(String id, int delay){
        super(id);
        this.delay=delay;
    }
    public void run(){
        String id=this.getName();
        try{
            sleep(delay);
        }
        catch(InterruptedException e){
            System.out.println("Thread: "+id+" foi interompida");
        }
        System.out.println(">>"+id+" "+delay);
    }
}
