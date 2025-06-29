class A{
    A(){
        System.out.print("Default Constructor Called ");
    }
    A(int a){
        this();
        System.out.print(a);
    }
}


class Tk_In_DC{
    public static void main(String[] args) {
        A obj = new A(10);

    }
}