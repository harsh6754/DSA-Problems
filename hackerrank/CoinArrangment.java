import java.util.Scanner;
public class CoinArrangment {
    public static int maxCoins(int N, int M, int X, int Y) {
        int maxCoins = 0;

        if (N == 1 || M == 1) {
            maxCoins = N * M * X;  
            return maxCoins;
        }
        int diagonalSize = (X <= Y) ? X : Y;
        maxCoins = diagonalSize;
        for (int i = 2; i <= N; i++) {
            for (int j = 2; j <= M; j++) {
                if ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0)) {
                    maxCoins += diagonalSize;
                } else {
                    maxCoins += (X <= Y) ? X : Y;
                }
            }
        }
        return maxCoins;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int X = scanner.nextInt();
        int Y = scanner.nextInt();
        int result = maxCoins(N, M, X, Y);
        System.out.println(result);
    }
}