class Demo {
    int x;
    String y;

    Demo(int a, String b) {
        x = a;
        y = b;
        System.out.println(x + " " + y);
    }

    Demo(Demo ref) {
        x = ref.x;
        y = ref.y;
        System.out.println(x + " " + y);
    }
}

class B {
    public static void main(String[] args) { // <-- Corrected method name
        Demo r = new Demo(10, "Harsh");
        Demo rf = new Demo(r);
    }
}