public class NestedIfStatement {
    public static void main(String[] args) {
        int a = 50;

        if (a == 50) {
            System.out.println("a is 50");
            if (a < 50) {
                System.out.println("a is 50");
                if (a < 75) {
                    System.out.println("a is 75");
                }
            }
        }
    }
}
