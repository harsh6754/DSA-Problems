import java.util.Scanner;

public class Sort {
    public static void main(String args[]) {
        try (Scanner sc = new Scanner(System.in)) {
            int i, j, n, t;
            System.out.println("enter the value of n:");
            int[] a = new int[20];
            n = sc.nextInt();
            System.out.println("enter the value array");
            for (i = 0; i < n; i++)
                a[i] = sc.nextInt();
            System.out.println("After sorting");
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    if (a[i] < a[j]) {
                        t = a[i];
                        a[i] = a[j];
                        a[j] = t;
                    }
                }
            }
            for (i = 0; i < n; i++) {
                System.out.println(a[i] + "\t");
            }
            sc.close();
        }
    }

}
