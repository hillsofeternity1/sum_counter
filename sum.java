public class Main {

  public static void main(String[] args) {
    long start = System.currentTimeMillis();
    long number = 1_000_000_000;
    long result = 0;

    for (int i = 0; i < number; i++) {
      if (i<10){
        result += i;
      }else {
        result = result + (number % 10) + (number/10);
      }
    }
    System.out.println(result);
    long finish = System.currentTimeMillis();
    long elapsed = finish - start;
    System.out.println("Прошло времени, мс: " + elapsed);
  }
}