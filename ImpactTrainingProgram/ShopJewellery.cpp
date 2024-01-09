#include <iostream>
#include <cmath>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to count the number of divisors for a given number
int countDivisors(int num) {
    int count = 0;
    for (int i = 1; i <= num; ++i) {
        if (num % i == 0) {
            count++;
        }
    }
    return count;
}

// Function to calculate the discount percentage
int calculateDiscount(int index1, int index2) {
    int discount = 0;

    for (int i = index1; i <= index2; ++i) {
        if (isPrime(countDivisors(i))) {
            discount++;
        }
    }

    return discount;
}

int main() {
    int index1, index2;

    // Input the indices of the respective jewelry items
    std::cin >> index1 >> index2;

    // Calculate and output the discount percentage
    std::cout << calculateDiscount(index1, index2) << std::endl;

    return 0;
}
