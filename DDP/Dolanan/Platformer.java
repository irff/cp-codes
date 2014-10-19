/*
	TODO : 
	1. Fixing ball initial speed
	2. Setting ball color
	3. Add gaming feature
*/

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.Timer;
import java.util.*;

public class Platformer extends JFrame {
	private static final double G = 9.81;
	private DrawCanvas canvas;
	private ArrayList<Bola> bola = new ArrayList<Bola>();

	public Platformer() {
		canvas = new DrawCanvas();
		canvas.setPreferredSize(new Dimension(1000,530));
		addMouseListener(new MouseAdapter(){
			public void mousePressed(MouseEvent e) {
				Bola b = new Bola(0,500, e.getX() / 6,(500 - e.getY()) / 3, Color.GREEN);
				bola.add(b);
			}
		});

		addMouseMotionListener(new MouseAdapter() {
			public void mouseDragged(MouseEvent e) {
				Bola b = new Bola(0,500, e.getX() / 6, (500 - e.getY()) / 3, Color.GREEN);
				bola.add(b);
			}
		});

		Container cp = getContentPane();
		cp.setLayout(new BorderLayout());
		cp.add(canvas, BorderLayout.CENTER);

		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("Platformer Game - Tri Ahmad Irfan");
		pack();
		setVisible(true);
	}

	class DrawCanvas extends JPanel {
		public void paintComponent(Graphics g) {
			super.paintComponent(g);
			setBackground(Color.WHITE);
			for(int i = 0; i < bola.size(); i++) {
				bola.get(i).paint(g);
			}
		}
	}


	public static void main(String[] args) {
		final Platformer now = new Platformer();
		
		class TimerListener implements ActionListener
		{
			public void actionPerformed(ActionEvent event) {
				for(int i = 0; i < now.bola.size(); i++) {
					Bola b = now.bola.get(i);
					if(b.getY() > 500) {
						b.setVY(-b.getVY() * 0.8);
						b.setY(b.getY() - b.getVY() * 0.1);
					} else {
						b.setVY(b.getVY() - G * 0.1);
					}

					if(b.getX() > 970) {
						b.setVX(-b.getVX());
					}

					b.setX(b.getX() + b.getVX() * 0.1);
					b.setY(b.getY() - b.getVY() * 0.1);
					now.canvas.repaint();
				}
			}
		}

		ActionListener listener = new TimerListener();
		
		Timer t = new Timer(10, listener);
		t.start();
	}
}