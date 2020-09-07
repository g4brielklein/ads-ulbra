package atividade02;
public class Atividade02 {
    public static void main(String[] args) {
        Celular c1 = new Celular();
        c1.marca = "Apple";
        c1.cor = "Preto";
        c1.armazenamento = 64;
        c1.ligar();
        c1.telefonar();
        
        Estudar e = new Estudar();
        e.disciplina = "POO";
        e.professor = "Gustavo Guanabara";
        e.plataforma = "YouTube";
        e.praticar();
        e.aprender();
    }
}
