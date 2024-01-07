#include <iostream>
using namespace std;

//const double pi = 3.14;

#define PI 3.14

int main()
{
    int r;
    double area;

    cout << "Enter the radius: ";
    cin >> r;

    area = PI * r * r;

    cout << "Area of the circle: " << area << endl;

    return 0;
}
