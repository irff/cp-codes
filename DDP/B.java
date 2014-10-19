  public class X {

 	
public static void main (String[] args) {	

 		int a = 20;

 		int b = 10;

 		int terbesar = 0;

 			

 		findMax(terbesar, a, b);

 		System.out.print(terbesar + " ");

 		

 		Integer a1 = 20;

 		Integer b1 = 10;

 		Integer terbesar1 = 0;

 			

 		findMaxNG(terbesar1, a1, b1);

 		System.out.println(terbesar1);

 		

 	}

 	

 	public static void findMax (int max, int a, int b) {

 		if (a > b) {

 			max = a;

 		} else {

 			max = b;

 		}

 	}

 	

 	public static void findMaxNG (Integer max, Integer a, Integer b) {

 		if (a > b) {

 			max = a;

 		} else {

 			max = b;

 		}

 	}

 }
