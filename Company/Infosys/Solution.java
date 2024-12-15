import java.io.*;
import java.util.*;

public class Solution {

    public static int calculate(int N, List<Integer> Arr) {
        final int MOD = 1000000007;

        // Find the maximum height
        int maxHeight = Collections.max(Arr);

        long years = 0;

        // Loop through each building
        for (int height : Arr) {
            int diff = maxHeight - height;

            // Calculate the number of 2-unit increments needed
            int evenIncrements = diff / 2;

            // Calculate the number of 1-unit increments needed
            int oddIncrements = diff % 2;

            // Total years are the sum of both increments
            years += evenIncrements + oddIncrements;
        }

        // Return result modulo MOD
        return (int) (years % MOD);
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int N = Integer.parseInt(scan.nextLine().trim());

        // Read the heights in one line
        String[] heights = scan.nextLine().split(" ");
        List<Integer> Arr = new ArrayList<>(N);
        for (String heightStr : heights) {
            Arr.add(Integer.parseInt(heightStr));
        }

        int result = calculate(N, Arr);

        System.out.println(result);
    }
}
