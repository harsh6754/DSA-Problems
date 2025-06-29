class A{
    void add(){
        int a = 10; int n = 20; String s = "Hello";
        System.out.println("Sum of a and n: " + (a + n));
    }
    void add(int x, int y){
        int c;
        c = x + y;
        System.out.println("Sum of x and y: " + c);
    }
    void add(int p, double q){
        double r;
        r = p + q;
        System.out.println("Sum of p and q: " + r);
    }
}

class Compile_Time_Polymorphism {
    public static void main(String[] args) {
        A obj = new A();
        obj.add(); // Calls the first add method
        obj.add(10, 20); // Calls the second add method
        obj.add(10, 20.5); // Calls the third add method
    }
}