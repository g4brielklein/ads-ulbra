package produtorconsumidor;
public class Gerencia {
    private int conteudo;
    private boolean disponivel;
    
    
    public synchronized void set(int nProdutor, int valor){
        while(disponivel == true){
            try {
                
                System.out.println("Produtor aguardando...");
                wait();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        conteudo = valor;
        System.out.println("Produtor inseriu :" + conteudo);
        disponivel = true;
        notifyAll();
    }
    
    public synchronized int get(int nConsumidor){
        while (disponivel == false) {
            try {
                System.out.println("Consumidor aguardando...");
                wait();
            } catch (Exception e) {
                e.printStackTrace();
            }            
        }
        System.out.println("Consumirdor consumiu :"+ conteudo);
        disponivel = false;
        notifyAll();
        return conteudo;
    }
}