class A{
    private int value;
    
    public void setValue(int x){
       value = x;
    }

    public int getValue(){
        return value;
    }
}

class encap{
    public static void main(String[] args) {
        A obj = new A();
        obj.setValue(100);
        System.out.println("Value is: " + obj.getValue());
    }
}