import java.util.Arrays;

public class MatrixMultiplication {
    public static void main(String[] args) {
        // Create arrays A and B with 3x3 matrix
        int[][] A = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
        int[][] B = { { 9, 8, 7 }, { 6, 5, 4 }, { 3, 2, 1 } };

        // Create array RES to store multiplication of A and B
        int[][] RES = new int[3][3];

        // Multiply arrays A and B and store the result in RES
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int sum = 0;
                for (int k = 0; k < 3; k++) {
                    sum += A[i][k] * B[k][j];
                }
                RES[i][j] = sum;
            }
        }

        // Print out all three arrays
        System.out.println("Array A:");
        for (int i = 0; i < 3; i++) {
            System.out.println(Arrays.toString(A[i]));
        }

        System.out.println("Array B:");
        for (int i = 0; i < 3; i++) {
            System.out.println(Arrays.toString(B[i]));
        }

        System.out.println("Array RES:");
        for (int i = 0; i < 3; i++) {
            System.out.println(Arrays.toString(RES[i]));
        }
    }
}
