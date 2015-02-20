import java.awt.*;
import java.awt.geom.Line2D;

/**
 * Created by mitchellmohorovich on 15-02-20.
 * starts with two single lines, but grows and grows
 */
public class DragonCurve
{
    final Line2D.Double startLine1;
    final Line2D.Double startLine2;

    final Line2D.Double[] startLines = new Line2D.Double[2];
    private Line2D.Double[] oldLines;
    private Line2D.Double[] currentLines;

    public DragonCurve()
    {
        //arbitrary x1,y1 = (64.0, 128.0) x2,y2 = (128.0, 64.0)
        //arbitrary x1,y1 = (128.0, 64.0) x2,y2 = (192.0, 128.0)
        this(new Line2D.Double(64.0, 128.0, 128.0, 64.0), new Line2D.Double(128.0, 192.0, 64.0, 128.0));

    }

    public DragonCurve(Line2D.Double startLine1, Line2D.Double startLine2) {
        startLines[0] = this.startLine1 = startLine1;
        startLines[1] = this.startLine2 = startLine2;
        currentLines = startLines;
    }

    public void calculateNextIteration()
    {
        //oldLines = currentLines;
        //currentLines = new Line2D.Double[oldLines.length * 2];
    }

    public void draw(Graphics2D g2)
    {
        for(Line2D.Double ld : currentLines) {
            System.out.printf("%s was drawn\n", ld.toString());
            g2.draw(ld);
        }
    }
}
