// Exemplo 1

import javax.swing.*;
public class TestaJanela { // Objeto Janela
    public static void main (String args[]) {
        static JFrame janela = new JFrame("Título da janela");
        janela.setBounds(50, 100, 400, 150); // Seta posicao e tamanho
        janela.setDefaultCloseOperation( WindowConstants.DISPOSE_ON_CLOSE);
        janela.setVisible(true); // Exibe a janela
    }
}

// Exemplo 2

import javax.swing.*;
import java.awt.*;
public class TestaContainer {
    public static void main (String args[ ]) {
        int i;
        JFrame janela = new JFrame("Título da janela");
        janela.setBounds(50, 100, 400, 150); // Seta posição e tamanho
        janela.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
        FlowLayout flow = new FlowLayout(); // Define o layout do container
        Container caixa = janela.getContentPane(); // Define o tamanho
        caixa.setLayout(flow); // Seta layout do container
        for (i=1; i<=6; i++)
        caixa.add(new JButton("Aperte " + i)); // Adiciona um botão
        janela.setVisible(true); // Exibe a janela
    }
}

// Exemplo 3
import javax.swing.*;
class SimpleFrame {
    public static void main(String args[ ]) {
        JFrame frame = new JFrame(“Swing Application”);
        JButton but = new JButton(“I am a Swing button”);
        JLabel texto = new JLabel(“Number of button clicks: 0”);
        JPanel painel = new JPanel( );
        painel.add(but);
        painel.add(texto);
        frame.getContentPane( ).add(painel);
        frame.pack( );
        frame.show( );
    }
}