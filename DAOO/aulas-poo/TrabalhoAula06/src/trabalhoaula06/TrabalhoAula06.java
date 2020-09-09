package trabalhoaula06;
import java.util.ArrayList;
import java.util.LinkedList;

public class TrabalhoAula06 {
    public static void main(String[] args) {
        ArrayList<Aluno> vetor = new ArrayList<>();
        System.out.println(vetor.toString());

        // Inserir um objeto: 
        Aluno a1 = new Aluno();
        a1.setNome("Gabriel");
        vetor.add(a1);
        System.out.println(vetor.toString());

        // Inserir um objeto em uma posição
        Aluno a2 = new Aluno();
        a2.setNome("Ciclano");
        vetor.add(0, a2);
        System.out.println(vetor.toString());

        // Buscar um objeto
        if (vetor.contains(a1)) {
            System.out.println("O objeto está no ArrayList!");
        } else {
            System.out.println("Objeto não encontrado.");
        }

        // Listar todos os objetos:
        System.out.println("Vetor: " + vetor.toString());

        // Remover um objeto:
        vetor.remove(a2);
        System.out.println(vetor.toString());

        // Remover um objeto de uma posição
        vetor.remove(0);
        System.out.println(vetor.toString());
        
        System.out.println("------------------------------------");
        System.out.println("-----------LinkedList---------------");
        
        LinkedList <Aluno> listaLigada = new LinkedList<Aluno>();
        
        // Inserir um objeto:
        Aluno gabriel = new Aluno();
        gabriel.setNome("Gabriel");
        listaLigada.add(gabriel);
        
        // Inserir um objeto em uma posição:
        Aluno fulano = new Aluno();
        fulano.setNome("Fulano");
        listaLigada.add(1, fulano);
        
        // Buscar um objeto
        System.out.println(listaLigada.get(0));
        
        // Listar todos os objetos: 
        for (int i = 0; i < listaLigada.size(); i++) {
            System.out.println(listaLigada.get(i));
        }
        
        // Remover um objeto
        listaLigada.remove(fulano);
        
        // Remover um objeto de uma posição
        listaLigada.remove(0);
        
        for (int i = 0; i < listaLigada.size(); i++) {
            System.out.println(listaLigada.get(i));
        }
    
    }
}
