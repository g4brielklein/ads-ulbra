package produtorconsumidor;

import java.util.Random;

public class ProdutorConsumidor {
    public static void main(String[] args) {
        Gerencia gerenciaTudo = new Gerencia();
        Produtor produtor = new Produtor(1, gerenciaTudo, 10);
        Consumidor consumidor = new Consumidor(1, gerenciaTudo, 10);
        produtor.start();
        consumidor.start();   
    }
}