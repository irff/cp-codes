/*
	Nama	: Tri Ahmad Irfan
	NPM		: 1306398983
	Asisten : Helmi Fakhriandy R.
*/

import java.awt.*;

/*
	Kelas Bonus.
	Bonus adalah sub-kelas dari Sesuatu, yang mempunyai sebuah value bonus.
*/
public class Bonus extends Sesuatu {
	//Instance variables
	private int value;

	//Konstruktor
	public Bonus(double x, double y, int width, int height, double vx, double vy, int value, Color color) {
		super(x, y, width, height, vx, vy, color);
		this.value = value;
	}

	//Daftar setter & getter
	public void setValue(int value) {
		this.value = value;
	}

	public int getValue() {
		return value;
	}

}