// This code demonstrates the use of a private constructor in a class.


class A {
    int a;
    int b;
    String s;

    private A(int x, int y, String str) {
        a = x;
        b = y;
        s = str;
        System.out.println(a + " " + b + " " + s);
    }

    static A createInstance(int x, int y, String str) {
        return new A(x, y, str);
    }

    void show() {
        System.out.println(a + " " + b + " " + s);
    }
}

class Main {
    public static void main(String[] args) {
        A obj = A.createInstance(30, 40, "World"); // Access via static method
        obj.show();
    }
}