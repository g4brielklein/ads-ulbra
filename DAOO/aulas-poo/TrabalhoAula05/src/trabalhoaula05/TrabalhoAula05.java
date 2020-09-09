package trabalhoaula05;

import java.util.ArrayList;

public class TrabalhoAula05 {
    public static void main(String[] args) {
        ArrayList<Mesa> mesa = new ArrayList<>();
        
        Mesa mesa1 = new Mesa();
        mesa1.setNumero(1);
        mesa1.setCliente("Gabriel");
        mesa1.setPedido("Pizza");
        mesa1.setValor(39.90f);
        mesa.add(mesa1);
        
        for (int i = 0; i < mesa.size(); i++) {
            System.out.println(mesa1.getNumero());
            System.out.println(mesa1.getCliente());
            System.out.println(mesa1.getPedido());
            System.out.println(mesa1.getValor());
        }
    }
}
