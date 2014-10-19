  public class Soal1 {  

 

   static int i = 200;

 

   int k = 10;

 

   public Soal1() { i++; k++; }

   

   public static void turun() { i--; }

 

   public static void main( String[] args ) {

 

     Soal1 s1 = new Soal1();

 

     System.out.print("k: " + s1.k + "; i: " + s1.i + " ");

 

     Soal1 s2 = new Soal1();

 

     System.out.print("k: " + s2.k + "; i: " + s2.i);

 

   }

 

 }
