/*
	Nama	: Tri Ahmad Irfan
	NPM		: 1306398983
	Asisten : Helmi Fakhriandy R.
*/

import java.awt.*;

/*
	Buah adalah objek bonus yang turun dari langit dan apabila bertabrakan dengan bola, maka skor player akan bertambah sesuai dengan angka yang tertera.
*/
public class Buah extends Bonus {

	// konstruktor
	public Buah(double x, double y, double vy, int value) {
		super(x, y, 75, 75, 0, vy, value, Color.GREEN);
	}

	// menggambar buah
	public void paintBuah(Graphics g) {
		int _x = (int) Math.round(super.getX());
		int _y = (int) Math.round(super.getY());

		g.setColor(super.getColor());
		g.fillOval(_x, _y, width, height);

		//Menulis value skor
		g.setColor(Color.BLACK);
		g.drawString(""+super.getValue(), _x+28, _y+45);
	}

}