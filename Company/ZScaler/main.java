import java.utils.*;
public class main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            int t = scanner.nextInt();

            while (t-- > 0) {
                int n = scanner.nextInt();
                List<List<Integer>> bitArrays = new ArrayList<>();

                for (int i = 0; i < n; i++) {
                    int m = scanner.nextInt();
                    List<Integer> bits = new ArrayList<>();

                    for (int j = 0; j < m; j++) {
                        bits.add(scanner.nextInt());
                    }

                    bitArrays.add(bits);
                }

                List<Integer> result = sortBinaryNumbers(bitArrays);
                System.out.println(result);
            }
        } finally {
            scanner.close(); // Close the scanner after use
        }
    }

    public static List<Integer> sortBinaryNumbers(List<List<Integer>> bitArrays) {
        // Create a list to store decimal values and original indices
        List<Pair> indexedValues = new ArrayList<>();

        // Convert each list of bit indices to decimal numbers
        for (int idx = 0; idx < bitArrays.size(); idx++) {
            List<Integer> bits = bitArrays.get(idx);
            // Calculate the decimal value from bit positions
            int value = 0;
            for (int bit : bits) {
                value += 1 << bit;
            }
            // Append the decimal value and the original index to the list
            indexedValues.add(new Pair(value, idx));
        }

        // Sort based on decimal values in descending order
        Collections.sort(indexedValues, (a, b) -> Integer.compare(b.value, a.value));

        // Extract the sorted indices based on the sorted decimal values
        List<Integer> sortedIndices = new ArrayList<>();
        for (Pair pair : indexedValues) {
            sortedIndices.add(pair.index);
        }

        return sortedIndices;
    }

    static class Pair {
        int value;
        int index;

        public Pair(int value, int index) {
            this.value = value;
            this.index = index;
        }
    }
}