/*
	Nama	: Tri Ahmad Irfan
	NPM		: 1306398983
	Asisten : Helmi Fakhriandy R.
*/

import java.awt.*;

/*
	Kelas Bola.
	Merupakan sub kelas dari sesuatu.
	Bola adalah objek utama di game ini, dapat ditembakkan untuk memperoleh tambahan amunisi & skor.
	Jumlah bola adalah jumlah amunisi.
	Setiap bola memiliki warna yang berbeda-beda.
*/
public class Bola extends Sesuatu {
	//Konstruktor
	public Bola(double x, double y, double vx, double vy, Color color) {
		super(x, y, 30,30, vx, vy, color);
	}

	//Menggambar bola
	public void paint(Graphics g) {
		g.setColor(super.getColor());
		int _x = (int)Math.round(super.getX());
		int _y = (int)Math.round(super.getY());
		g.fillOval(_x, _y, height, width);
		g.setColor(Color.BLACK);
		
		//Menggambar mata, paruh, dan sayap
		if(super.getVX() < 0) {
			g.fillOval(_x-6, _y+7, 12, 6);
			g.fillOval(_x+10, _y+5, 8, 8);
			g.fillOval(_x+15, _y+12, 25, 12);
		} else {
			g.fillOval(_x+13, _y+5, 8, 8);
			g.fillOval(_x+27, _y+7, 12, 6);
			g.fillOval(_x-10, _y+12, 25, 12);
		}

	}
}