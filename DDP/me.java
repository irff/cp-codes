 class TheInteger {

 	int x;

 	

 	public TheInteger(int x) {

 		this.x = x;

 	}

 }

 

 public class A {

 	public static void swap(TheInteger obj1, TheInteger obj2) {

 		TheInteger temp = obj1;

 		obj1 = obj2;

 		obj2 = temp;

 	}

 	

 	public static void main(String[] args) {

 		TheInteger obj1 = new TheInteger(1);

 		TheInteger obj2 = new TheInteger(2);

 		

 		swap(obj1, obj2);

 		System.out.print(obj1.x + " " + obj2.x);

 	}

 }
