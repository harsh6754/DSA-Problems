class Student{
    int roll;
    int marks;
    String name;
    void input(){
        System.out.println("Enter roll, marks and name");
    }
}

class Teacher extends Student{
    String TeacherName;
    int id;
    int classNu;
    void input(){
        roll = 101;
        marks = 90;
        name="Harsh";
        id = 1;
        classNu = 12;
        TeacherName = "Mr. Sharma";
    }
    void display(){
        System.out.println("ID: " + id + ", Name: " + name + ", Marks: " + marks + 
                           ", Class: " + classNu + ", Teacher: " + TeacherName);
    }

    public static void main(String[] args){
        Teacher obj = new Teacher();
        obj.input();
        obj.display();
    }
}

class Principle extends Student{
    String PrincipleName;
    String schoolName;
    void input(){
        roll = 102;
        marks = 95;
        name = "Alice";
        PrincipleName = "Mr. Smith";
        schoolName = "ABC High School";
    }
    void display(){
        System.out.println("Name: " + name + ", Marks: " + marks + 
                           ", Principle: " + PrincipleName + ", School: " + schoolName);
    }

    public static void main(String[] args){
        Principle obj = new Principle();
        obj.input();
        obj.display();
    }
}

public class Hirarchical_Inheritance {
    public static void main(String[] args) {
        Teacher teacher = new Teacher();
        teacher.input();
        teacher.display();

        Principle principle = new Principle();
        principle.input();
        principle.display();
    }
}