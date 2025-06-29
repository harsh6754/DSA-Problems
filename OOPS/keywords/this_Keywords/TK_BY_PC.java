class A{
    A(){
        this(10);
    }
    A(int a){
        System.out.println("Constructor with parameter: " + a);
    }
}

class TK_BY_PC {
    public static void main(String[] args) {
        A obj = new A(); // This will call the default constructor which in turn calls the parameterized constructor
        // Output: Constructor with parameter: 10
    }
}