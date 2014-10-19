/*
	Nama	: Tri Ahmad Irfan
	NPM		: 1306398983
	Asisten : Helmi Fakhriandy R.
*/

import java.awt.*;

/*
	Kelas Sesuatu.
	Sesuatu adalah objek yang mempunyai posisi, mempunyai kecepatan, mempunyai panjang, mempunyai lebar, serta mempunyai warna.

*/
public class Sesuatu {
	//Instance variables
	private double x, y, vx, vy;
	int width, height;
	private Color color;

	//Konstruktor sesuatu
	public Sesuatu(double x, double y, int width, int height, double vx, double vy, Color color) {
		this.x = x;
		this.y = y;
		this.width = width;
		this.height = height;
		this.vx = vx;
		this.vy = vy;
		this.color = color;
	}

	//Daftar setter & getter
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

	public void setWidth(int width) {
		this.width = width;
	}

	public int getWidth() {
		return width;
	}

	public void setHeight(int height) {
		this.height = height;
	}

	public int getHeight() {
		return height;
	}

	public void setColor(Color color) {
		this.color = color;
	}

	public Color getColor() {
		return color;
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

 
}