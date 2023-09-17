public class TwoDimensionalArray {
    public static void main(String[] args) {
        int arr[][]= { 
            {2,3,4},
            {5,6,7},
            {8,9,0}
        };

        for(int i =0;i<3;i++)
        {
            for(int j = 0;j<3;j++)
            {
                System.out.print(arr[i][j]+ " ");
            }
            System.out.println();
        }
        System.out.println(arr[2][1]);
    }
}
