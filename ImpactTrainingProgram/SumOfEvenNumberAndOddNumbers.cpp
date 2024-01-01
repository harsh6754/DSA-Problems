#include <iostream>

int main() {
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    int even = 0;
    int odd = 0;

    for (int i = 0; i < n; ++i) {
        int num;
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> num;

        if (num % 2 == 0) {
            even += num;
        } else {
            odd += num;
        }
    }

    std::cout << "The sum of the even numbers in the array is " << even << std::endl;
    std::cout << "The sum of the odd numbers in the array is " << odd << std::endl;

    return 0;
}

