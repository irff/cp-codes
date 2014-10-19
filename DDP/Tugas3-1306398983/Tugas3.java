/*
	Nama 	: Tri Ahmad Irfan
	NPM  	: 1306398983
	Asisten : Helmi Fakhriandi R.
*/

// import library yang dibutuhkan
import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.geom.*;
import java.awt.event.*;

// Kelas untuk sebuah lingkaran
class Circle {

	//posisi x, dan y lingkaran
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

	//method untuk menggambar lingkaran dengan ukuran 30*30
	public void draw(Graphics2D g2) {
		Ellipse2D.Double circle = new Ellipse2D.Double(x,y,30,30);
		g2.draw(circle);

	}
}

// Kelas untuk satu lintasan berisi banyak lingkaran
class CircleComponent extends JComponent {
	private Track track;
	public CircleComponent(Track track) {
		this.track = track;
	}

	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		Graphics2D g2 = (Graphics2D) g;
		
		double x = track.getX();
		double y = track.getY();
		double kecepatan_x = track.getKecepatanX();
		double kecepatan_y = track.getKecepatanY();

		//Basis interval, agar penghitungan menjadi akurat
		double base_interval = 0.1;

		//Counter untuk warna
		int counter = 0;
		for(double t = 0.0; t <= track.getWaktu(); t += base_interval) {
			kecepatan_y -= track.getGravitasi() * base_interval;
			x = x + kecepatan_x * base_interval;
			y = y - kecepatan_y * base_interval;
			if( y >= 600 ) {
				kecepatan_y *= -1;
			}
			//Ketika keluar dari layar, berhenti menggambar
			if(x < -50 || x > 1400 || y < -50 || y > 800) break;

			//Jika t sekarang masuk dalam interval lintasan
			if( ((int)Math.round(t * 10)) % ((int) track.getInterval()) == 0) {
				Circle circle = new Circle(x,y);
				if(counter % 5 == 0) g2.setColor(Color.red);
				else g2.setColor(Color.black);
				circle.draw(g2);
				counter++;
			}
		}
	}
}

//Kelas untuk menyimpan informasi lintasan
class Track {
	private double x;
	private double y;
	private double interval;
	private double waktu;
	private double kecepatan_x;
	private double kecepatan_y;

	//Mengubah sudut dari derajat ke radian
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

//Kelas utama
public class Tugas3 {
	//Frame utama
	static JFrame frame = new JFrame();
	
	//Slider-slider sebagai input, parameter JSlider(min,max, nilai_sekarang)
	static JSlider xSlider			= new JSlider(0,1200,600);
	static JSlider ySlider			= new JSlider(0,600,600);
	static JSlider intervalSlider	= new JSlider(1,50,3);
	static JSlider waktuSlider		= new JSlider(0,100,30);
	static JSlider sudutSlider		= new JSlider(0,180,135);
	static JSlider kecepatanSlider = new JSlider(0,200,100);

	//Tombol-tombol kontrol
	static JButton button = new JButton("Toss a new ball!");
	static JButton clear = new JButton("Clear canvas");
	
	//Panel kontrol
	static JPanel panel = new JPanel();
	
	//Panel slider
	static JPanel panelSlider = new JPanel();

	//Membuat lintasan baru
	static Track buildNewTrack() {
		int x 			= xSlider.getValue();
		int y 			= ySlider.getValue();
		int interval 	= intervalSlider.getValue();
		int waktu 		= waktuSlider.getValue();
		int sudut 		= 180 - sudutSlider.getValue();
		int kecepatan 	= kecepatanSlider.getValue();
		Track baru = new Track(x, y, interval, waktu, sudut, kecepatan);
		return baru;
	}

	//Menggambar lintasan baru pada kanvas
	static void toss(Track bola) {
		CircleComponent component = new CircleComponent(bola);
		frame.add(component);
		frame.setVisible(true);
	}

	//Mengatur tampilan slider
	static void setSlider(JSlider now, String caption) {
		JPanel innerPanel = new JPanel(new GridLayout(2,1));
		innerPanel.setBackground(Color.cyan);
		now.setBackground(Color.cyan);
		innerPanel.add(new JLabel(caption), JLabel.CENTER);
		innerPanel.add(now);
		panelSlider.add(innerPanel);
	}

	public static void main(String args[]) {

		//Mengatur tampilan frame
		frame.setSize(1366,768);
		frame.setTitle("Tugas 3 - Tri Ahmad Irfan - 1306398983");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);

		//Meberikan warna latar hitam pada panel kontrol
        panel.setBackground(Color.black);

		//Menambah tombol pada panel kontrol
		panel.add(button);
		panel.add(clear);
		
		//Mengatur tampilan untuk masing-masing slier
		setSlider(xSlider, 			"  0                    Posisi X               1200");
		setSlider(ySlider, 			"  0                    Posisi Y                 600");
		setSlider(intervalSlider, 	"  0.1                  Interval                  5.0");
		setSlider(waktuSlider, 		"  0                     Waktu                   100");
		setSlider(sudutSlider, 		"  0                     Sudut                    180");
		setSlider(kecepatanSlider, 	"  0                 Kecepatan               200");

		//Mengatur tampilan panel slider 
		panelSlider.setBackground(Color.cyan);
		panelSlider.setPreferredSize(new Dimension(1366, 100));

		//Menambah panel slider pada panel kontrol
		panel.add(panelSlider);

		//Menambah panel kontrol pada frame utama
		frame.add(panel, BorderLayout.NORTH);

		//Listener untuk membuat lintasan baru
		class TossListener implements ActionListener {
			public void actionPerformed(ActionEvent event) {

				final Track bola = buildNewTrack();
				toss(bola);
			}
		}

		//Listener untuk menghapus kanvas
		class ClearListener implements ActionListener {
			public void actionPerformed(ActionEvent event) {
				frame.getContentPane().removeAll();
				frame.getContentPane().revalidate();
				frame.getContentPane().repaint();
				frame.add(panel, BorderLayout.NORTH);
			}
		}

		//Menambahkan action listener untuk masing-masing tombol
		ActionListener tossListener = new TossListener();
		button.addActionListener(tossListener);
		ActionListener clearListener = new ClearListener();
		clear.addActionListener(clearListener);

	}
}