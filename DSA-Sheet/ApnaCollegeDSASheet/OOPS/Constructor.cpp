// Special Methods invoked automatically at time of object creation.
//Use for Initialization of data members.   
// Same name as class name. 
// no return type.  
// Only called once at the time of object creation.
// Memory allocation happens when constructor is called
//Initialized multiple same name class but different parameters.


#include<bits/stdc++.h>
using namespace std;
class Teacher{
    private:
    double salary;

    public:
    Teacher(){
        cout << "Constructor called" << endl;
        dept = "CSE";
    }
    string name;
    string dept;
    string subject;

    void changeDept(string newDept){
        dept = newDept;
    }

    void setSalary(double s){
        salary = s;
    }

    double getSalary(){
        return salary;
    }
};

class Account{
    private:
    string password;
    string balance;

    public:
    // Non-parameterized constructor
    Account(){
        cout << "Constructor called" << endl;
        password = "default";
    }
    string accountId;
    string userName;

    void setPassword(string pass){
        password = pass;
    }

    void setBalance(string bal){
        balance = bal;
    }

    string getPassword(){
        return password;
    }

    string getBalance(){
        return balance;
    }
};

class Student{
    private:
    string password;

    public:
  
    // Parameterized constructor
    Student(string n,string r,string c){
        name = n;
        rollno = r;
        classNo = c;
        password = "default";
    }

    string name;
    string rollno;
    string classNo;

    void setPassword(string pass){
        password = pass;
    }

    string getPassword(){
        return password;
    }

};

class Principal{
    private:
    string password;

    public:
    string name;
    string position;
    string id;

    void setPassword(string pass){
        password = pass;
    }
    string getPassword(){
        return password;
    }

    Principal(string name, string pos, string id){
        this->name = name;
        this->position = pos;
        this->id = id;
    }
};


int main()
{
    Teacher t1;
    t1.name = "John Doe";
    t1.subject = "Algebra";

    t1.setSalary(50000);
    cout << "Name: " << t1.name << endl;
    cout << "Department: " << t1.dept << endl;
    cout << "Subject: " << t1.subject << endl;
    cout << "Salary: $" << t1.getSalary() << endl;

    t1.changeDept("Physics");
    cout << "New Department: " << t1.dept << endl;

    Account a1;
    a1.accountId = "A12345";
    a1.userName = "johndoe";

    a1.setBalance("1000.00");
    cout << "Account ID: " << a1.accountId << endl;
    cout << "Username: " << a1.userName << endl;
    cout << "Password: " << a1.getPassword() << endl;
    cout << "Balance: $" << a1.getBalance() << endl;

    Student s1("John Doe", "12345", "10th Grade");
    cout << "Student Name: " << s1.name << endl;
    cout << "Roll No: " << s1.rollno << endl;
    cout << "Class: " << s1.classNo << endl;
    cout << "Password: " << s1.getPassword() << endl;


    Principal p1("Dr. Smith", "Principal", "P001");
    cout << "Principal Name: " << p1.name << endl;
    cout << "Position: " << p1.position << endl;
    cout << "ID: " << p1.id << endl;
    p1.setPassword("admin123");
    cout << "Principal Password: " << p1.getPassword() << endl;
    



    return 0;
}

// Types of Constructors:
// 1. Non-parameterized Constructor
// 2. Parameterized Constructor
// 3. Copy Constructor
// 4. Private Constructor
// 5. Static Constructor