package ap1;
public class Aluno {
    private String nome;
    private int matricula;

    public Aluno(String nome, int matricula) {
        this.nome = nome;
        this.matricula = matricula;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getMatricula() {
        return matricula;
    }

    public void setMatricula(int matricula) {
        this.matricula = matricula;
    }
    
    public void status() {
        System.out.println("Dados do aluno: ");
        System.out.println("Nome: " + this.getNome());
        System.out.println("Matrícula: " + this.getMatricula());
    }

}
