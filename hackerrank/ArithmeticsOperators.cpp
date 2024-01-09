#include <iostream>

class ArithmeticOperations {
private:
    int add_op1, add_op2, sub_op1, sub_op2, mul_op1, mul_op2, div_op1, div_op2;

public:
    ArithmeticOperations(int a, int b, int c, int d, int e, int f, int g, int h) {
        add_op1 = a;
        add_op2 = b;
        sub_op1 = c;
        sub_op2 = d;
        mul_op1 = e;
        mul_op2 = f;
        div_op1 = g;
        div_op2 = h;
    }

    int addition() {
        return add_op1 + add_op2;
    }

    int subtraction() {
        return sub_op1 - sub_op2;
    }

    int multiplication() {
        return mul_op1 * mul_op2;
    }

    double division() {
        if (div_op2 != 0) {
            return static_cast<double>(div_op1) / div_op2;
        } else {
            std::cerr << "Error: Cannot divide by zero\n";
            return 0;
        }
    }
};

int main() {
    // Input
    int add_op1, add_op2, sub_op1, sub_op2, mul_op1, mul_op2, div_op1, div_op2;
    std::cin >> add_op1 >> add_op2 >> sub_op1 >> sub_op2 >> mul_op1 >> mul_op2 >> div_op1 >> div_op2;

    // Create an object of the class
    ArithmeticOperations calculator(add_op1, add_op2, sub_op1, sub_op2, mul_op1, mul_op2, div_op1, div_op2);

    // Output
    std::cout << calculator.addition() << std::endl;
    std::cout << calculator.subtraction() << std::endl;
    std::cout << calculator.multiplication() << std::endl;
    std::cout << calculator.division() << std::endl;

    return 0;
}

