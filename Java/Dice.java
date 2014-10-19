class CoinThrowing {
  
  public static void main(String[] args) {
    double x = Math.random();
    if (x < 0.5) System.out.println("Head " + x);
    else System.out.println("Tail " + x);
  }

}