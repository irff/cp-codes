/*
	Nama	: Tri Ahmad Irfan
	NPM		: 1306398983
	Asisten : Helmi Fakhriandy R.
*/

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.Timer;
import java.util.*;

/*
	Kelas Platformer. Merupakan sub-kelas dari JFrame.
	Untuk menampung semua elemen
*/
public class Platformer extends JFrame {

	// Daftar instance variables
	private static final double G = 9.81;
	private DrawCanvas canvas;
	private ArrayList<Bola> bola = new ArrayList<Bola>();
	private ArrayList<Kardus> kardus = new ArrayList<Kardus>();
	private ArrayList<Buah> buah = new ArrayList<Buah>();

	//Jumlah amunisi, jika amunisi habis maka tidak bisa menembak
	private int amunisi = 0;

	//Jumlah skor
	private int skor	= 0;

	//Method untuk menghasilkan warna random
	public Color randomizeColor() {
		int red = (int) (Math.random() * 256);
		int green = (int) (Math.random() * 256);
		int blue = (int) (Math.random() * 256);

		Color c = new Color(red, green, blue);
		
		return c; 
	}

	//Konstruktor Platformer
	public Platformer() {
		//Listener jika mouse di pencet
		addMouseListener(new MouseAdapter(){
			public void mousePressed(MouseEvent e) {
				if(amunisi > 0) {
					Bola b = new Bola(0,500, e.getX() / 6,(500 - e.getY()) / 3, randomizeColor());
					bola.add(b);
					amunisi--;
				}
			}
		});

		//Listener jika mouse dipencet dan diseret
		addMouseMotionListener(new MouseAdapter() {
			public void mouseDragged(MouseEvent e) {
				if(amunisi > 0) {
					Bola b = new Bola(0,500, e.getX() / 6, (500 - e.getY()) / 3, randomizeColor());
					bola.add(b);
					amunisi--;
				}
			}
		});

		//Setting layout
		Container cp = getContentPane();
		cp.setLayout(new BorderLayout());

		canvas = new DrawCanvas();
		canvas.setPreferredSize(new Dimension(1000,530));
		cp.add(canvas, BorderLayout.CENTER);

		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("Platformer Game - Tri Ahmad Irfan");
		pack();
		setVisible(true);
	}

	//inner class DrawCanvas, merupakan sub-kelas dari JPanel
	class DrawCanvas extends JPanel {

		//overriding method paintComponent
		public void paintComponent(Graphics g) {
			super.paintComponent(g);
			setBackground(Color.WHITE);

			//Menulis informasi Amunisi & Skor
			g.setFont(new Font("Arial", Font.PLAIN, 20));
			g.setColor(Color.BLACK);
			g.drawString("AMUNISI 	= " + amunisi, 40,40);
			g.drawString("SKOR 		= " + skor, 40, 60);

			//Menggambar bola / burung
			for(int i = 0; i < bola.size(); i++) {
				bola.get(i).paint(g);
			}

			//Menggambar kardus amunisi
			for(int i = 0; i < kardus.size(); i++) {
				kardus.get(i).paintKardus(g);
			}

			//Menggambar buah skor
			for(int i = 0; i < buah.size(); i++) {
				buah.get(i).paintBuah(g);
			}

		}
	}

	//Main Method untuk game ini
	public static void main(String[] args) {
		//Membuat JFrame Platformer
		final Platformer now = new Platformer();
		
		//Amunisi pertama
		now.amunisi = 50;

		//Timer listener untuk animasi
		class TimerListener implements ActionListener
		{
			public void actionPerformed(ActionEvent event) {
				
				//Animasi bola
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

					if(b.getY() < -1) {
						b.setY(b.getY() + 2);
						b.setVY(b.getVY() * -1);
					}

					b.setX(b.getX() + b.getVX() * 0.1);
					b.setY(b.getY() - b.getVY() * 0.1);
					if(b.getX() < -30) {
						now.bola.remove(i);
					}
					now.canvas.repaint();
				}
				
				//Animasi kardus amunisi
				for(int i = 0; i < now.kardus.size(); i++) {
					Kardus k = now.kardus.get(i);
					k.setY(k.getY() + k.getVY());
					k.setVY(k.getVY() + G * 0.005);
					now.canvas.repaint();
					if(k.getY() < -50) {
						now.kardus.remove(i);
					}
				}

				//Animasi buah skor
				for(int i = 0; i < now.buah.size(); i++) {
					Buah bh = now.buah.get(i);
					bh.setY(bh.getY() + bh.getVY());
					bh.setVY(bh.getVY() + G * 0.005);
					now.canvas.repaint();
					if(bh.getY() < -75) {
						now.buah.remove(i);
					}
				}

				//Collision detection antara bola dan kardus amunisi
				boolean kardusCollide = false;
				for(int i = 0; !kardusCollide && i < now.kardus.size(); i++) {
				
					for(int j = 0; !kardusCollide && j < now.bola.size(); j++) {
						Kardus k = now.kardus.get(i);
						Bola b = now.bola.get(j);

						if(b.getX() + 30 > k.getX() && b.getX() < k.getX() + 100) {
							if(b.getY() + 30 > k.getY() && b.getY() < k.getY() + 50) {
								now.amunisi += k.getValue();
								now.kardus.remove(i);
								now.bola.remove(j);
								kardusCollide = true;
							}
						}

					}
				}

				//Collision detection antara bola dan buah skor
				boolean buahCollide = false;
				for(int i = 0; !buahCollide && i < now.buah.size(); i++) {
					for(int j = 0; !buahCollide && j < now.bola.size(); j++) {
						Buah bh = now.buah.get(i);
						Bola b = now.bola.get(j);

						if(b.getX() + 30 > bh.getX() && b.getX() < bh.getX() + 75) {
							if(b.getY() + 30 > bh.getY() && b.getY() < bh.getY() + 75) {
								now.skor += bh.getValue();
								now.buah.remove(i);
								now.bola.remove(j);
								buahCollide = true;
							}
						}
					}
				}
			}
		}

		//Timer listener untuk kemunculan kardus amunisi
		class TimerKardusListener implements ActionListener {
			public void actionPerformed(ActionEvent event) {
				Kardus k = new Kardus(Math.random() * 900, 0, (int)(Math.random() * 10), 0.5 + Math.random() * 3);
				now.kardus.add(k);
			}

		}

		//Timer listener untuk kemunculan buah skor
		class TimerBuahListener implements ActionListener {
			public void actionPerformed(ActionEvent event) {
				Buah bh = new Buah(Math.random() * 900, 0, 0.5 + Math.random() * 4, 10 + (int)(Math.random() * 30) );
				now.buah.add(bh);
			}
		}

		//Memulai timer animasi
		ActionListener listener = new TimerListener();
		Timer t = new Timer(10, listener);
		t.start();

		//Memulai timer kemunculan kardus amunisi
		ActionListener kardusListener = new TimerKardusListener();
		Timer tk = new Timer(1500, kardusListener);
		tk.start();

		//Memulai timer kemunculan buah skor
		ActionListener buahListener = new TimerBuahListener();
		Timer tbh = new Timer(1000, buahListener);
		tbh.start();
	}
}