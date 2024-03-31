import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    scanner.nextLine(); // consume newline

    Map<String, Integer> bookCounts = new HashMap<>();
    for (int i = 0; i < n; i++) {
      String[] response = scanner.nextLine().split(", ");
      for (String bookTitle : response) {
        bookCounts.put(bookTitle, bookCounts.getOrDefault(bookTitle, 0) + 1);
      }
    }

    for (Map.Entry<String, Integer> entry : bookCounts.entrySet()) {
      System.out.println(entry.getKey() + ": " + entry.getValue());
    }
  }
}