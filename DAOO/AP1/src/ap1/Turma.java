package ap1;

import java.util.ArrayList;

public class Turma {
    private int numero;
    private String modalidade;
   
    ArrayList<Aluno> alunos = new ArrayList<>();
    ArrayList<Turma> turma = new ArrayList<>();

    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public String getModalidade() {
        return modalidade;
    }

    public void setModalidade(String modalidade) {
        this.modalidade = modalidade;
    }

    public ArrayList<Aluno> getAlunos() {
        return alunos;
    }

    public void setAlunos(ArrayList<Aluno> alunos) {
        this.alunos = alunos;
    }

    public ArrayList<Turma> getTurma() {
        return turma;
    }

    public void setTurma(ArrayList<Turma> turma) {
        this.turma = turma;
    }
    
    public void status() {
        System.out.println("Informações da turma: ");
        System.out.println("Número: " + getNumero());
        System.out.println("Modalidade: " + getModalidade());
    }
    
    public void adicionarTurma(int n, String m) {
        if (turma.contains(n)) {
            System.out.println("Já existe uma turma com esse número!");
        } else {
            this.setNumero(n);
            this.setModalidade(m);
            turma.add(this);
        }
    } 
}
