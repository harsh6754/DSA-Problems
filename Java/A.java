
class A {
    int a = 10;
    int b = 5;

    public void display()

    {
        System.out.println(a);

    }

    public void disp(int x)
    {
        System.out.println(x+a);
    }

    public int disp() {
        return (a + b);
    }
};

class hai
{

    public static void main(String[] args) {
        A obj = new A();
        obj.disp();
        obj.disp(4);
        int x = obj.disp();
        System.out.println(x);
    }
}
