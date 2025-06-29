class A{
    void shape(){
        System.out.println("Shape Cant be defined");
    }
}
class Circle extends A{
    @Override
    void shape(){
        super.shape(); // Calls the method from class A
        System.out.println("Circle is a shape");
    }
}
class RunTime_Polymorphism {
    public static void main(String[] args) {
        A obj = new Circle(); // Upcasting
        obj.shape(); // Calls the overridden method in Circle class
    }
}