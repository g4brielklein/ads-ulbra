package ap1;

import java.util.ArrayList;

public class AP1 {
    public static void main(String[] args) {
        
        ArrayList<Aluno> alunos = new ArrayList<>();
        ArrayList<Turma> turma = new ArrayList<>();
        
        Turma turma01 = new Turma();
        turma01.adicionarTurma(1, "Crossfit");
        turma.add(turma01);
        
        Turma turma02 = new Turma();
        turma02.adicionarTurma(1, "Musculação");
        turma02.status();
    } 
}
