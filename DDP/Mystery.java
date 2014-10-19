import java.util.ArrayList;

public class Mystery{
 public boolean misteri(int[] arr) {

 	boolean[] tes = new boolean[arr.length];

 

 	for (int i= 0; i< arr.length; i++) {

 		tes[arr[i]-1] = true;

 	}

 	

 	for (int i = 0; i< tes.length; i++) {

 		if (!tes[i])

 			return false;

 	}

 

 	return true;

 }
 public void method1 (char[] w) {

 	int x = w.length;

 	char c;

 	for (int i = 0, j = x-1; i < x; i++, j--) {

 		w[i] = w[j];

 	}

 	

 	for (int i = 0; i < w.length; i++) {

 		System.out.print(w[i] + " ");

 	}

 }
 	public static void main(String[] args){


 		int arr[] = {1, 4, 5, 3, 2, 3};

 		

 		double x;

 		for(int i=0; i < arr.length; i++){

 			x = x*arr[i];

 		}

 		System.out.println(x);

	}

}