// Build with: 
// javac -d . Sum.java && java -cp . Sum

public class Sum {
  public static void main(String[] args) {
    long start = System.currentTimeMillis();
    long number = 1_000_000_000;
    long result = 0;

    for (int i = 0; i <= number; i++) {
        long tmp = i;
        while (tmp > 0) {
            result = result + tmp % 10;
            tmp = tmp / 10;
        }
    }
    System.out.println(result);
    long finish = System.currentTimeMillis();
    long elapsed = finish - start;
    System.out.println("Прошло времени, мс: " + elapsed);
  }
}
