public class ib {
    int a; int b;
    {
        a = 30;
        b = 40;
        System.out.println("Instance Block 2: a = " + a + ", b = " + b);
    }
    ib(){
        a = 10;
        b = 20;
        System.out.println("Instance Block 1: a = " + a + ", b = " + b);
    }
    public static void main(String[] args) {
        ib obj = new ib();
        System.out.println("Main method executed: a = " + obj.a + ", b = " + obj.b);
    }
}