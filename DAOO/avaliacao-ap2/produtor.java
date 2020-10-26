package produtorconsumidor;
public class Produtor extends Thread{
    private int nProdutor;
    private Gerencia pilha;
    private int totalProducao;
    
    public Produtor(int n, Gerencia p, int totalProducao){
        nProdutor = n;
        pilha = p;
        this.totalProducao = totalProducao;
    }
    
    public void run(){
        for (int i = 0; i < totalProducao; i++) {
            pilha.set(nProdutor, i);
        }
        System.out.println("Produtor :" + nProdutor);
    }
}
