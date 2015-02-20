import javax.swing.*;

/**
 * Created by mitchellmohorovich on 15-02-20.
 * just the window to hold the component
 */
public class LineFrame extends JFrame
{
    LineComponent component;

    LineFrame(LineComponent c)
    {
        component = c;
        this.add(c);
    }

    void start()
    {
        component.startFractal();
    }
}
