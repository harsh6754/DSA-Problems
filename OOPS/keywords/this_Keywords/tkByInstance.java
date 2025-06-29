class A{
    int a = 10;
    A(int a){
        this.a = a; // Using 'this' to refer to the instance variable    
    }
    void show(){
        System.out.println("Value of a: " + this.a); // Using 'this' to refer to the instance variable
    }
}

public class tkByInstance {
    public static void main(String[] args){
        A obj = new A(20); // Creating an instance of class A
        obj.show(); // Calling the show method to display the value of a
    }
}