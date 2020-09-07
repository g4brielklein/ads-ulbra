package atividade02;
public class Estudar {
    String disciplina;
    String professor;
    String plataforma;
    boolean praticou;
    boolean assistiuVideos;
    
    void assistirVideos() {
        assistiuVideos = true;
    }
    
    void praticar() {
        praticou = true;
    }
    
    void aprender() {
        if (praticou == true) {
            System.out.println("Você está aprendendo!");
        } else {
            System.out.println("Você não está aprendendo!");
        }
    }
}
