import javax.swing.*;
import java.awt.*;

/**
 * Created by mitchellmohorovich on 15-02-20.
 * draws a DragonCurve object and modifies it
 */
public class LineComponent extends JComponent
{
    DragonCurve dc;
    public final int iterations = 10;

    LineComponent() {
        dc = new DragonCurve();
    }

    public void startFractal() {
        int currentIteration = 0;
        do {
            fractalLoop();
            currentIteration++;
        } while(currentIteration < iterations);
    }

    public void fractalLoop() {
        System.out.println("Looping");
        dc.calculateNextIteration();
        System.out.println("painting (in fractalLoop())");
        repaint();

        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public void paintComponent(Graphics g)
    {
        System.out.println("paintComponent()");
        Graphics2D g2 = (Graphics2D) g;
        g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
        g2.setColor(Color.black);
        dc.draw(g2);
        g2.setBackground(Color.blue);

    }
}
