import java.util.Scanner;

public class SGPCalculator {
	static final double MAX			= 100.0;
	static final double A_LOW		= 85.0;
	static final double A_MIN_LOW	= 80.0;
	static final double B_PLUS_LOW	= 75.0;
	static final double B_LOW		= 70.0;
	static final double B_MIN_LOW	= 65.0;
	static final double C_PLUS_LOW	= 60.0;
	static final double C_LOW 		= 55.0;
	static final double C_MIN_LOW	= 50.0;
	static final double D_LOW		= 40.0;
	static final double EPSILON		= 1e-6;

	public static boolean inRange(double n, double a, double b) {
		if( n >= a && n < b) return true;
		return false;
	}

	public static String convertToLetter(double score) {
		if(inRange(score, A_LOW, MAX))				return "A";
		if(inRange(score, A_MIN_LOW, A_LOW))		return "A-";
		if(inRange(score, B_PLUS_LOW, A_MIN_LOW))	return "B+";
		if(inRange(score, B_LOW, B_PLUS_LOW))		return "B";
		if(inRange(score, B_MIN_LOW, B_LOW))		return "B-";
		if(inRange(score, C_PLUS_LOW, B_MIN_LOW))	return "C+";
		if(inRange(score, C_LOW, C_PLUS_LOW))		return "C";
		if(inRange(score, C_MIN_LOW, C_LOW))		return "C-";
		if(inRange(score, D_LOW, C_MIN_LOW))		return "D";
		return "E";
	}

	public static double letterValue(String letter) {
		if(letter.equals("A"))	return 4.0;
		if(letter.equals("A-"))	return 3.7;
		if(letter.equals("B+"))	return 3.3;
		if(letter.equals("B"))	return 3.0;
		if(letter.equals("B-"))	return 2.7;
		if(letter.equals("C+"))	return 2.3;
		if(letter.equals("C"))	return 2.0;
		if(letter.equals("C-"))	return 1.7;
		if(letter.equals("D"))	return 1.0;
		return 0.0;
	}

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		
		int course1Credit, course2Credit, course3Credit;
		double course1Score, course2Score, course3Score;
		
		course1Credit	= sc.nextInt();
		course1Score	= sc.nextDouble();
		course2Credit	= sc.nextInt();
		course2Score	= sc.nextDouble();
		course3Credit	= sc.nextInt();
		course3Score	= sc.nextDouble();

		String course1Letter, course2Letter, course3Letter;
		
		course1Letter = convertToLetter(course1Score);
		course2Letter = convertToLetter(course2Score);
		course3Letter = convertToLetter(course3Score);

		double course1LetterValue, course2LetterValue, course3LetterValue;
		
		course1LetterValue = letterValue(course1Letter);
		course2LetterValue = letterValue(course2Letter);
		course3LetterValue = letterValue(course3Letter);

		double semesterValue = 0.0;
		int totalCredit;

		totalCredit = course1Credit + course2Credit + course3Credit;

		semesterValue += course1Credit * course1LetterValue;
		semesterValue += course2Credit * course2LetterValue;
		semesterValue += course3Credit * course3LetterValue;

		semesterValue /= totalCredit;
		
		System.out.println("Nilai huruf mata kuliah 1: " + course1Letter);
		System.out.println("Nilai huruf mata kuliah 2: " + course2Letter);
		System.out.println("Nilai huruf mata kuliah 3: " + course3Letter);

		System.out.printf("IP Semester: %.2f", semesterValue);

	}
}