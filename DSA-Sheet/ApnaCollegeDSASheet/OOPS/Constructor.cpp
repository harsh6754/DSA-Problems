// Special Methods invoked automatically at time of object creation.
//Use for Initialization of data members.   
// Same name as class name. 
// no return type.  
// Only called once at the time of object creation.
// Memory allocation happens when constructor is called


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


    return 0;
}