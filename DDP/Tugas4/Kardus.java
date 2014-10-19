/*
	Nama	: Tri Ahmad Irfan
	NPM		: 1306398983
	Asisten : Helmi Fakhriandy R.
*/

import java.awt.*;

/*
	Kardus adalah objek bonus berisi tambahan amunisi yang turun dari langit.

	Ketika bertabrakan dengan bola, maka jumlah amunisi bertambah sesuai dengan angka yang tertera di kardus.
*/
public class Kardus extends Bonus {
	
	//Konstruktor
	public Kardus(double x, double y, int value, double vy) {
		super(x, y, 100, 50, 0, vy, value, Color.CYAN);
	}

	//menggambar kardus
	public void paintKardus(Graphics g) {
		int _x = (int) Math.round(super.getX());
		int _y = (int) Math.round(super.getY());

		g.setColor(super.getColor());
		g.fillRect(_x, _y, width, height);

		//Menulis jumlah amunisi
		g.setColor(Color.BLACK);
		g.drawString(""+super.getValue(), _x+45, _y+30);
	}

}