
class Main {

  public static void main(String[] args) {
    
    int firstNum = Integer.parseInt(args[0]);
    int secondNum = Integer.parseInt(args[1]);
    
    if( firstNum % secondNum == 0) {
      System.out.println(firstNum + " divides " + secondNum);
    } else if( secondNum % firstNum == 0) {
      System.out.println(secondNum + " divides " + firstNum);
    } else System.out.println("they don't divide each other");
  }

}