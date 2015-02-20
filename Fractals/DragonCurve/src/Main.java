import javax.swing.*;

public class Main {
    final static int HEIGHT = 800;
    final static int WIDTH = 1000;

    public static void main(String[] args) {
        System.out.println("Hello World!");
        LineFrame frame = new LineFrame(new LineComponent());
        frame.setSize(WIDTH, HEIGHT);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

        frame.start();
    }
}
