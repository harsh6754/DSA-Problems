class Teacher{
    int id;
    String name;
    long phone;
    void input(){
        System.out.println("Enter id,name, phone");
    }
}
class Student extends Teacher{
    int classNu;
    String TeacherName;
    String name;
    void display(){
        id=101;
        name="Harsh";
        phone=1234567890;
        classNu=12;
        TeacherName="Mr. Sharma";
        System.out.println("ID: " + id + ", Name: " + name + ", Phone: " + phone + 
                           ", Class: " + classNu + ", Teacher: " + TeacherName);
    }
}

public class multi_level_Inheritance extends Student {
    public static void main(String[] args){
        multi_level_Inheritance obj = new multi_level_Inheritance();
        obj.input();
        obj.display();
        Student student = new Student();
        student.input();
        student.display();
    }
}