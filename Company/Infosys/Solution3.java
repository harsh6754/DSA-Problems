import java.io.*;
import java.util.*;

public class Solution3 {

    private static final int MOD = 1000000007;

    public static int getFrequencyMultiplication(int N, List<Integer> P, List<Integer> A) {
        List<List<Integer>> tree = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            tree.add(new ArrayList<>());
        }

        for (int i = 1; i < N; i++) {
            tree.get(P.get(i)).add(i);
        }

        Map<Integer, Integer> mexFrequencies = new HashMap<>();

        boolean[] visited = new boolean[N];
        dfs(0, tree, A, mexFrequencies, visited);

        long result = 1;
        for (int freq : mexFrequencies.values()) {
            if (freq > 0) {
                result = (result * freq) % MOD;
            }
        }

        return (int) result;
    }

    private static Set<Integer> dfs(int node, List<List<Integer>> tree, List<Integer> A,
                                     Map<Integer, Integer> mexFrequencies, boolean[] visited) {
        visited[node] = true;

        Set<Integer> values = new TreeSet<>();

        values.add(A.get(node));

        for (int child : tree.get(node)) {
            if (!visited[child]) {
                values.addAll(dfs(child, tree, A, mexFrequencies, visited));
            }
        }

        int mex = 0;
        for (int value : values) {
            if (value == mex) {
                mex++;
            } else {
                break;
            }
        }

        mexFrequencies.put(mex, mexFrequencies.getOrDefault(mex, 0) + 1);

        return values;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine().trim());

        List<Integer> P = new ArrayList<>(N);
        for (int j = 0; j < N - 1; j++) {
            P.add(Integer.parseInt(br.readLine().trim()));
        }

        List<Integer> A = new ArrayList<>();
        for (int j = 0; j < N; j++) {
            A.add(Integer.parseInt(br.readLine().trim()));
        }

        int result = getFrequencyMultiplication(N, P, A);

        System.out.println(result);
    }
}
