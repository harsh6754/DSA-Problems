// Encapsulation is a method to wrapping up of the data and member function into single unit just like a capsule is called encapsulation.

// Encapsulation are use to protect/hide sensitive data usind private access specifier. 

#include<bits/stdc++.h>
using namespace std;

class Teacher{
    private:
    double salary;

    public:
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
    string accountId;
    string username;

    void setPassword(string pass){
        password = pass;
    }   

    string getPassword(){
        return password;
    }

    void setBalance(string bal){
        balance = bal;
    }

    string getBalance(){
        return balance;
    }

};


int main()
{
    Teacher t1;
    t1.name = "John Doe";
    t1.dept = "Mathematics";
    t1.subject = "Algebra";
    t1.setSalary(50000);
    cout << "Name: " << t1.name << endl;
    cout << "Department: " << t1.dept << endl;
    cout << "Subject: " << t1.subject << endl;
    cout << "Salary: $" << t1.getSalary() << endl;
    t1.changeDept("Physics");
    cout << "New Department: " << t1.dept << endl;

    Account a1;
    a1.accountId = "123456789";
    a1.username = "johndoe";

    // a1.password = "password"; // This line will cause an error because password is private
    // a1.balance = "1000"; // This line will cause an error because balance is private

    a1.setPassword("password");
    a1.setBalance("1000");
    cout << "Account ID: " << a1.accountId << endl;
    cout << "Username: " << a1.username << endl;
    cout << "Password: " << a1.getPassword() << endl;
    cout << "Balance: " << a1.getBalance() << endl;
    


    return 0;
}