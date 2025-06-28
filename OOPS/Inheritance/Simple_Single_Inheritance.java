class Student{
    int roll,marks;
    String name;
    void input(){
        System.out.println("Enter roll, marks and name");
    }
}
public class Simple_Single_Inheritance extends Student {
    void disp(){
        roll = 101;
        marks = 90;
        name="Harsh";
        System.out.println(roll + " " + marks + " " + name);
    }
    public static void main(String[] args){
        Simple_Single_Inheritance obj = new Simple_Single_Inheritance();
        obj.input();
        obj.disp();
    }
}
