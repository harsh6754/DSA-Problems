public class NonPrimitiveDataTypes{
    public static void main(String[] args) {
        String str ="test";
        System.out.println("String is :" + str);

        String str1 = new String("Test");
        System.out.println("Another String Is : "+ str1);

        int arr[];
        arr = new int[2];
        arr[0] = 0;
        arr[1] = 1;
        //arr[2] = 2;

        System.out.println(arr);
        System.out.println(arr[0]);
    }
}