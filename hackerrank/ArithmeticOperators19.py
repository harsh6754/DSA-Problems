class ArithmeticOperations:
    def __init__(self, num1_add, num2_add, num1_sub, num2_sub, num1_mul, num2_mul, num1_div, num2_div):
        self.num1_add = num1_add
        self.num2_add = num2_add
        self.num1_sub = num1_sub
        self.num2_sub = num2_sub
        self.num1_mul = num1_mul
        self.num2_mul = num2_mul
        self.num1_div = num1_div
        self.num2_div = num2_div

    def addition(self):
        return self.num1_add + self.num2_add

    def subtraction(self):
        return self.num1_sub - self.num2_sub

    def multiplication(self):
        return self.num1_mul * self.num2_mul

    def division(self):
        if self.num2_div != 0:
            return self.num1_div / self.num2_div
        else:
            return "Cannot divide by zero"

# Input
num1_add = int(input())
num2_add = int(input())
num1_sub = int(input())
num2_sub = int(input())
num1_mul = int(input())
num2_mul = int(input())
num1_div = int(input())
num2_div = int(input())

# Create an object of the ArithmeticOperations class
arithmetic_obj = ArithmeticOperations(num1_add, num2_add, num1_sub, num2_sub, num1_mul, num2_mul, num1_div, num2_div)

# Output
print(arithmetic_obj.addition())
print(arithmetic_obj.subtraction())
print(arithmetic_obj.multiplication())
print(arithmetic_obj.division())
