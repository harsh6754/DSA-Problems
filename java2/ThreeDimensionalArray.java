public class ThreeDimensionalArray {
    public static void main(String[] args) {
        int arr[][][] = {
            {
                          {1,2,3},
                          {4,5,6},
                          {7,8,9}
            },
            {
                {1,2,3},
                {4,5,6},
                {7,8,9}
            },
            {
                {1,2,3},
                {4,5,6},
                {7,8,9}
            }

        };
        for(int i=0;i<3;i++)
        {
            for(int j = 0;j<3;j++)
            {
                for(int k = 0;k< 3 ;k++)
                {
                    System.out.print(arr[i][j][k] + " ");
                }
                System.out.println();
            }
        }
    }
}
