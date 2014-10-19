import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Rectangle;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.geom.Ellipse2D;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.JSlider;
import javax.swing.event.ChangeListener;
import javax.swing.event.ChangeEvent;
import javax.swing.*;
import java.awt.*;

class Circle {
	private double x;
	private double y;

	public Circle(double x, double y) {
		this.x = x;
		this.y = y;
	}
	
	public double getX() {
		return x;
	}

	public void setX(double x) {
		this.x = x;
	}

	public double getY() {
		return y;
	}

	public void setY(double y) {
		this.y = y;
	}
	public void draw(Graphics2D g2) {
		Ellipse2D.Double circle = new Ellipse2D.Double(x,y,30,30);
		g2.draw(circle);

	}
}

class CircleComponent extends JComponent {
	private Track track;
	public CircleComponent(Track track) {
		this.track = track;
	}

	public void paintComponent(Graphics g) {
		Graphics2D g2 = (Graphics2D) g;
		
		double x = track.getX();
		double y = track.getY();
		double kecepatan_x = track.getKecepatanX();
		double kecepatan_y = track.getKecepatanY();

		for(double t = 0.0; t <= track.getWaktu(); t += track.getInterval()) {
			kecepatan_y -= track.getGravitasi() * track.getInterval();
			x = x + kecepatan_x * track.getInterval();
			y = y - kecepatan_y * track.getInterval();

			if(x < 0 || x > 1300 || y < 0 || y > 700) break;

			Circle circle = new Circle(x,y);
			circle.draw(g2);
		}
	}
}

class Track {
	private double x;
	private double y;
	private double interval;
	private double waktu;
	private double kecepatan_x;
	private double kecepatan_y;

	private double getRadian(double derajat) {
		return (Math.PI / 180.0) * derajat;
	}
	public double getGravitasi() {
		return 9.81;
	}
	public double getX() {
		return x;
	}
	public double getY() {
		return y;
	}
	public double getInterval() {
		return interval;
	}

	public double getWaktu() {
		return waktu;
	}

	public double getKecepatanX() {
		return kecepatan_x;
	}

	public double getKecepatanY() {
		return kecepatan_y;
	}

	public Track(double x, double y, double interval, double waktu, double sudut, double kecepatan) {
		this.x 			= x;
		this.y 			= y;
		this.interval 	= interval;
		this.waktu 		= waktu;

		double sudut_radian = getRadian(sudut);
		double cos_radian = Math.cos(sudut_radian);
		double sin_radian = Math.sin(sudut_radian);

		this.kecepatan_x = kecepatan * cos_radian;
		this.kecepatan_y = kecepatan * sin_radian;
	}

}

public class Tugas3 extends JFrame{
	static JFrame frame = new JFrame();
	static JPanel kanvas = new JPanel();
	static JPanel panel = new JPanel();
	static JSlider xSlider			= new JSlider(0,1200,600);
	static JSlider ySlider			= new JSlider(200,600,600);
	static JSlider intervalSlider	= new JSlider(1,50,3);
	static JSlider waktuSlider		= new JSlider(0,100,30);
	static JSlider sudutSlider		= new JSlider(0,180,135);
	static JSlider kecepatanSlider = new JSlider(0,200,100);

	public Tugas3() {
		Container c = getContentPane();
		c.add(panel, BorderLayout.NORTH);
		c.add(kanvas, BorderLayout.CENTER);

	}

	static Track buildNewTrack() {
		int x 			= xSlider.getValue();
		int y 			= ySlider.getValue();
		int interval 	= intervalSlider.getValue();
		int waktu 		= waktuSlider.getValue();
		int sudut 		= 180 - sudutSlider.getValue();
		int kecepatan 	= kecepatanSlider.getValue();
		Track baru = new Track(x, y, interval/10.0, waktu, sudut, kecepatan);
		return baru;
	}

	static void toss(Track bola) {
		CircleComponent component = new CircleComponent(bola);
		frame.add(component);
		frame.setVisible(true);
	}

	public static void main(String args[]) {

		JButton button = new JButton("Toss a new ball!");
		JButton clear 	= new JButton("Clear canvas");

		JPanel panelSlider = new JPanel();

		panelSlider.add(xSlider);
		panelSlider.add(ySlider);
		panelSlider.add(intervalSlider);
		panelSlider.add(waktuSlider);
		panelSlider.add(sudutSlider);
		panelSlider.add(kecepatanSlider);
		panelSlider.setBackground(Color.green);

		panelSlider.setPreferredSize(new Dimension(1366, 100));
        panelSlider.setMaximumSize(panelSlider.getPreferredSize()); 
        panelSlider.setMinimumSize(panelSlider.getPreferredSize());
		
		panel.add(button);
		panel.add(clear);
        panel.setBackground(Color.black);

		panel.add(panelSlider);
		
		Tugas3 frame = new Tugas3();
		frame.setSize(1366,768);
		frame.setTitle("Tugas 3 - Tri Ahmad Irfan - 1306398983");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);

			
		kanvas.setBackground(Color.blue);
		Graphics g = kanvas.getGraphics();
		g.setColor(Color.white);
		g.fillOval(300,300,50,50);


		class TossListener implements ActionListener {
			public void actionPerformed(ActionEvent event) {

				final Track bola = buildNewTrack();
				toss(bola);
			}
		}

		class ClearListener implements ActionListener {
			public void actionPerformed(ActionEvent event) {
			}
		}

		ActionListener tossListener = new TossListener();
		button.addActionListener(tossListener);
		ActionListener clearListener = new ClearListener();
		clear.addActionListener(clearListener);
	}
}