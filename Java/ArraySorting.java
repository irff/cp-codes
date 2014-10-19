import java.util.*;

class ArraySorting {

  public static void main(String[] args) {
    
    String[] str = {"Irfan", "Tri", "Ahmad"};
    Arrays.sort(str);
    
    System.out.println(Arrays.toString(str));
    
    double[] nums = {5.0, 0.0, 34.43434, -1.3, 500};
    Arrays.sort(nums);
    
    System.out.println(Arrays.toString(nums));
  }
}