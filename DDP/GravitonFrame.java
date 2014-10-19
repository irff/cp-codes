import javax.swing.*;
import java.awt.*;
import java.awt.geom.Ellipse2D;
import java.awt.Graphics;
import java.awt.Graphics2D;

class ElipseYeah extends JComponent {
	public static void paintComponent(Graphics g) {
		Ellipse2D.Double bunderan = new Ellipse2D.Double(100,100,100,100);
		g.setClip(bunderan);
		g.setColor(Color.cyan);
		g.fillRect(0,0,100,100);
	}

}

public class GravitonFrame extends JFrame {
	public GravitonFrame() {
		setLookAndFeel();
		setSize(720,480);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);
	}

	private void setLookAndFeel() {
		try {
			UIManager.setLookAndFeel(
				"com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel"
			);
		} catch (Exception exc) {
			//ignore
		}
	}

	public static void main(String args[]) {
		GravitonFrame grav = new GravitonFrame();
		EllipseYeah = new EllipseYeah();
	}

}
