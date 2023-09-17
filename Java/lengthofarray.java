public class lengthofarray {

    public static void main(String args[]) {
        int[][] test;
        test = new int[5][10];

        int row = test.length;
        int col = test[0].length;

        System.out.println(row);
        System.out.println(col);
    }
}