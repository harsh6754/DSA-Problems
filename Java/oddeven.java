
import java.util.*;

class oddeven {
    public static void main(String args[]) 
    {

        int[] a = new int[20];
        int[] b = new int[20];
        int[] c = new int[20];
        int i, j, n;
        try (Scanner sc = new Scanner(System.in)) {
            System.out.println("Enter the value of N:");
            n = sc.nextInt();
            System.out.println("Enter the values one by one:");
            for (i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
        }
        System.out.println("The even numbers are");
        for (i = 0; i < n; i++) {
            if (a[i] % 2 == 0)
                b[i] = a[i];
            else
                c[i] = a[i];
        }

        for (j = 0; j < n; j++) {
            System.out.println(b[j]);
            if (b[j] == '\0')
                break;
        }
        System.out.println("The odd numbers are");
        for (j = 0; j < n; j++) {
            System.out.println(c[j]);
            if (c[j] == '\0')
                break;
        }
    }
}