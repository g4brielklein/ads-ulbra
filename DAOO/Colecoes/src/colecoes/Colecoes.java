package colecoes;

import java.util.ArrayList;
import java.util.LinkedList;

public class Colecoes {
    public static void main(String[] args) {
        LinkedList linky = new LinkedList();
        
        linky.add("Teste");
        linky.add("Teste2");
        linky.add("Teste3");
        
        System.out.println(linky);
        
        linky.clear();
        
        System.out.println(linky);
        
        int[] arrayUm = {12,3,5,68,9,6,73,44,456,65,321};
        int[] arrayDois = {43,42,4,8,55,21,2,45};

        if(arrayDois.length > 8){
            System.out.println("Tamanho do ArrayDois - Maior que 8!");
        }else{
            System.out.println("Tamanho do ArrayDois - Menor que 8!");
        }
        
        ArrayList al = new ArrayList();
		al.add(3);
		al.add(2);
		al.add(1);
		al.add(4);
		al.add(5);
		al.add(6);
		al.add(6);
                
        System.out.println(al);        
    } 
}
