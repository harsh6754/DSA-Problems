abstract class Animal{
    public abstract void sound();
    public abstract void eat();
    void sleep(){
        System.out.println("Animal is sleeping");
    }
    
    Animal(){
        System.out.println("Animal constructor called");
    }
}
 
class Dog extends Animal{

    Dog(){
        super();
    }
  
    public void sound() {
        System.out.println("Dog barks");
    }
   
    public void eat() {
        System.out.println("Dog eats bones");
    }
     
    void sleep() {
        System.out.println("Dog is sleeping");
    }
}
class Lion extends Animal{
     
    Lion(){
        super();
    }
    public void sound() {
        System.out.println("Lion roars");
    }
    
    public void eat() {
        System.out.println("Lion eats meat");
    }
    
    void sleep() {
        System.out.println("Lion is sleeping");
    }
}

class ac{
    public static void main(String[] args) {
        Animal dog = new Dog();
        dog.sound(); // Dog barks
        dog.eat();   // Dog eats bones
        dog.sleep(); // Dog is sleeping

        Animal lion = new Lion();
        lion.sound(); // Lion roars
        lion.eat();   // Lion eats meat
        lion.sleep(); // Lion is sleeping
    }
}