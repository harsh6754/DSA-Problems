class A{
    void show(){
        System.out.println(this);
    }
    public static void main(String[] args){
        A obj = new A();
        System.out.println(obj);
    }
}

class tk {
    public static void main(String[] args){
        A obj = new A();
        obj.show(); // This will print the reference of the object
        System.out.println(obj); // This will also print the reference of the object
    }
}