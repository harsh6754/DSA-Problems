import java.util.Scanner;

public class KadysJumps {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the size of the plane (m x n):");
        int m = sc.nextInt();
        int n = sc.nextInt();

        System.out.println("Enter Kady's favorite jump distance (X):");
        int X = sc.nextInt();

        System.out.println("Enter Kady's starting position (p, q):");
        int p = sc.nextInt();
        int q = sc.nextInt();

        System.out.println("Enter Kady's destination position (u, v):");
        int u = sc.nextInt();
        int v = sc.nextInt();

        int minJumps = -1;

        // Check if destination is reachable based on distance and plane boundaries
        if (isReachable(p, q, u, v, X, m, n)) {
            // Calculate absolute differences in coordinates, ensuring they're multiples of X
            int dx = Math.abs(u - p);
            int dy = Math.abs(v - q);

            if (dx % X == 0 && dy % X == 0) {
                // Minimum jumps is the maximum of both coordinate differences
                minJumps = Math.max(dx / X, dy / X);
            }
        }

        System.out.println(minJumps);
    }

    private static boolean isReachable(int p, int q, int u, int v, int X, int m, int n) {
        // Check if destination is within plane boundaries
        if (u < 1 || u > m || v < 1 || v > n) {
            return false;
        }

        // Check if Euclidean distance between starting and ending points is a multiple of X
        int distance = (int) Math.sqrt(Math.pow(u - p, 2) + Math.pow(v - q, 2));
        return distance % X == 0;
    }
}
