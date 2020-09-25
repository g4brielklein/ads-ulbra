
public class TestePrioridade
{
    public static void main(String args[]){
        new Escrita5("Menor ",4).start();
        new Escrita5("Maior ",6).start();
        new Escrita5("Default ").start();
        for(int i=0;i<10;i++){
            System.out.println("MAIN "+i);
        }
    }
}
