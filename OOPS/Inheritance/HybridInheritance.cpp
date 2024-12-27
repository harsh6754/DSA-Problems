#include <iostream>
using namespace std;

// Base class
class Base {
public:
    void showBase() {
        cout << "This is the Base class" << endl;
    }
};

// First derived class
class Derived1 : public Base {
public:
    void showDerived1() {
        cout << "This is Derived1 class" << endl;
    }
};

// Second derived class
class Derived2 : public Base {
public:
    void showDerived2() {
        cout << "This is Derived2 class" << endl;
    }
};

// Hybrid child class inheriting from Derived1 and Derived2
class Child : public Derived1, public Derived2 {
public:
    void showChild() {
        cout << "This is the Child class" << endl;
    }
};

int main() {
    Child obj;

    // Access methods
    obj.showChild();
    obj.showDerived1();
    obj.showDerived2();
    
    // To avoid ambiguity, explicitly call the base class method
    obj.Derived1::showBase();  // Access Base through Derived1
    obj.Derived2::showBase();  // Access Base through Derived2

    return 0;
}
