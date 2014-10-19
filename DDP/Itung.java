public class Itung {
	public static void count(int n, String s) {
		if(n == 0) {
			System.out.println(s);
		} else {
			count(n-1, s + "1");
			if(n > 1) count(n-2, s + "2");
		}
	}

	public static void main(String args[]) {
		count(40, "");
	}
	
}