import java.util.*;

public class Solution {
    public static int countBalancingElements(List<Integer> arr) {
        int n = arr.size();
        if (n == 0) return 0;

        List<Integer> evenPrefixSum = new ArrayList<>(Collections.nCopies(n + 1, 0));
        List<Integer> oddPrefixSum = new ArrayList<>(Collections.nCopies(n + 1, 0));

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                evenPrefixSum.set(i + 1, evenPrefixSum.get(i) + arr.get(i));
                oddPrefixSum.set(i + 1, oddPrefixSum.get(i));
            } else {
                oddPrefixSum.set(i + 1, oddPrefixSum.get(i) + arr.get(i));
                evenPrefixSum.set(i + 1, evenPrefixSum.get(i));
            }
        }

        int resultCount = 0;

        for (int i = 0; i < n; i++) {
            int evenSumWithoutI = evenPrefixSum.get(i) + oddPrefixSum.get(n) - oddPrefixSum.get(i + 1);
            int oddSumWithoutI = oddPrefixSum.get(i) + evenPrefixSum.get(n) - evenPrefixSum.get(i + 1);

            if (evenSumWithoutI == oddSumWithoutI) {
                resultCount++;
            }
        }

        return resultCount;
    }

    public static void main(String[] args) {
        List<Integer> arr = Arrays.asList(2, 1, 6, 4);
        System.out.println(countBalancingElements(arr));  // Output: 1
    }
}
