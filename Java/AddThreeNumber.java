 

import java.util.Scanner;

// Java-W3schools
public class AddThreeNumber{

    public static void main(String[] args) {

        int number1;
        int number2;
        int number3;

        try (Scanner scanner = new Scanner(System.in)) {
            System.out.println("Enter numner 1 : ");
            number1 = scanner.nextInt();

            System.out.println("Enter numner 2 : ");
            number2 = scanner.nextInt();

            System.out.println("Enter numner 3 : ");
            number3 = scanner.nextInt();
        }
        int finalResult = number1 + number2 + number3;
        System.out.println("Final resut of sum of given three numbers is " + finalResult);

    }

}