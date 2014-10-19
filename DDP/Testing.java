 class Testing {

 	static int value;

 	

 	public Testing(int value) {

 		this.value = value;

 	}

 	

 	public static void proses() {

 		System.out.println(value);

 	}

 }

 

 public class A {

 	public static void main(String[] args) {

 		Testing t = new Testing(10);

 		t.proses();

 	}

 }

