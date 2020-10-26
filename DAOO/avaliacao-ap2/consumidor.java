package produtorconsumidor;
public class Consumidor extends Thread{
    private int nConsumidor;
    private Gerencia pilha;
    private int totalConsumir;
    
    public Consumidor(int n, Gerencia p, int totalConsumir){
        nConsumidor = n;
        pilha = p;
        this.totalConsumir = totalConsumir;
    }
    
    /* public void run() {
        
    } */
    public void run(){
        for (int i = 0; i < totalConsumir; i++) {
            pilha.get(nConsumidor);
        }
        System.out.println("Consumiu  :" + nConsumidor);
    }   
}
