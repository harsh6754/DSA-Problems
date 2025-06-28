// This code demonstrates the use of a private constructor in a class.
class A{
    int a;
    int b;
    String s;
    private A(int x, int y, String str) {
        a = x;
        b = y;
        s = str;
        System.out.println(a + " " + b + " " + s);
    }
    public static void main(String[] args) {
        A obj = new A(10, 20, "Hello"); // This will work
        // A obj2 = new A(30, 40, "World"); // This will not work as constructor is private
    }
}

