import java.io.*;
import java.util.*;
import java.math.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger total=BigInteger.ONE;
        BigInteger nol=BigInteger.ZERO;
        BigInteger n=sc.nextBigInteger();
        while(n.compareTo(nol)!=0){
            total=total.add(n);
            n=sc.nextBigInteger();
        }
        System.out.println(total);
    }
}
