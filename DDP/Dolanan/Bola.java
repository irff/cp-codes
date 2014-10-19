import java.awt.*;

public class Bola {
	private double x, y, vx, vy;
	private int height = 30, width = 30;
	private Color color;

	public Bola(double x, double y, double vx, double vy, Color color) {
		this.x = x;
		this.y = y;
		this.vx = vx;
		this.vy = vy;
		this.color = randomizeColor();
	}
	public Color randomizeColor() {
		int red = (int) (Math.random() * 256);
		int green = (int) (Math.random() * 256);
		int blue = (int) (Math.random() * 256);

		Color c = new Color(red, green, blue);
		
		return c; 
	}

	public void paint(Graphics g) {
		g.setColor(color);
		int _x = (int)Math.round(x);
		int _y = (int)Math.round(y);
		g.fillOval(_x, _y, height, width);
		g.setColor(Color.BLACK);
		if(vx < 0) {
			g.fillOval(_x-6, _y+7, 12, 6);
			g.fillOval(_x+10, _y+5, 8, 8);
			g.fillOval(_x+15, _y+12, 25, 12);
		} else {
			g.fillOval(_x+13, _y+5, 8, 8);
			g.fillOval(_x+27, _y+7, 12, 6);
			g.fillOval(_x-10, _y+12, 25, 12);
		}
	}

	public void setX(double x) {
		this.x = x;
	}

	public double getX() {
		return x;
	}

	public void setY(double y) {
		this.y = y;
	}

	public double getY() {
		return y;
	}

	public void setVX(double vx) {
		this.vx = vx;
	}

	public double getVX() {
		return vx;
	}

	public void setVY(double vy) {
		this.vy = vy;
	}

	public double getVY() {
		return vy;
	}

	public void setColor(Color color) {
		this.color = color;
	}

	public Color getColor() {
		return color;
	}
}