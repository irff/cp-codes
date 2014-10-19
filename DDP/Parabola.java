
import java.util.Scanner;
public class Parabola {
	static final double GRAVITASI = 9.8;

	/* Mengubah dari derajat menuju Radian */
	private static double getRadian(double derajat) {
		double radian;
		radian = (Math.PI / 180.0) * derajat;
		return radian;
	}

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);

		double kecepatan;
		double waktu;
		double sudut_derajat, sudut_radian;
		double posisi_x_awal, posisi_y_awal;
		
		//Input
		System.out.print("Masukkan posisi x awal (m): ");
		posisi_x_awal = sc.nextDouble();
		System.out.print("Masukkan posisi y awal (m): ");
		posisi_y_awal = sc.nextDouble();
		System.out.print("Masukkan sudut lemparan terhadap sumbu x (derajat): ");
		sudut_derajat = sc.nextDouble();
		System.out.print("Masukkan kecepatan awal (m/s): ");
		kecepatan = sc.nextDouble();
		System.out.print("Masukkan detik (s): ");
		waktu = sc.nextDouble();

		// menentukan sin dan cos
		sudut_radian = getRadian(sudut_derajat);
		double cos_radian = Math.cos(sudut_radian);
		double sin_radian = Math.sin(sudut_radian);

		// menentukan kecepatan horizontal dan vertikal
		double kecepatan_x = kecepatan * cos_radian;
		double kecepatan_y = kecepatan * sin_radian;

		// menentukan titik tertinggi yang dapat dicapai objek
		double waktu_tertinggi	= kecepatan_y / GRAVITASI;
		double posisi_y_maks	= kecepatan_y * waktu_tertinggi - 0.5 * GRAVITASI * waktu_tertinggi * waktu_tertinggi;

		double posisi_x, posisi_y;

		//jika objek masih bergerak naik
		if(waktu < waktu_tertinggi) {
			posisi_x = waktu * kecepatan_x;
			posisi_y = waktu * kecepatan_y - 0.5 * GRAVITASI * waktu * waktu;
		
		} 
		// jika objek sudah bergerak turun
		else {
			double waktu_jatuh = waktu - waktu_tertinggi;
			posisi_x = waktu * kecepatan_x;
			posisi_y = posisi_y_maks - 0.5 * GRAVITASI * waktu_jatuh * waktu_jatuh;
		}

		// output
		System.out.println();
		System.out.println("Pada detik ke " + waktu + " objek berada pada :");
		System.out.printf("Posisi x (m) : %6.2f\n", posisi_x);
		System.out.printf("Posisi y (m) : %6.2f\n", posisi_y);
		
	}
}