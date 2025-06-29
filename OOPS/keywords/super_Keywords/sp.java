class A{
    int a = 10;
    A(){
        System.out.println("Constructor of class A");
    }
}

class B extends A{
    int b = 20;
    B(){
        super(); // Calls the constructor of class A
        System.out.println("Constructor of class B");
    }
}

class sp {
    public static void main(String[] args){
        B obj = new B(); // This will call the constructor of A first, then B
        System.out.println("Value of a: " + obj.a);
        System.out.println("Value of b: " + obj.b);
    }
}