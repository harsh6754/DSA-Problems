#include <iostream>
#include <vector>

using namespace std;

// Abstract class representing list elements
class ListElement {
public:
    virtual ~ListElement() = default;

    virtual int getValue() const = 0;
};

// Concrete class for integers
class IntegerElement : public ListElement {
public:
    IntegerElement(int value) : value(value) {}

    int getValue() const override {
        return value;
    }

private:
    int value;
};

// Function to calculate the sum of list elements
int sumListElements(const vector<ListElement*>& list) {
    int sum = 0;
    for (const ListElement* element : list) {
        sum += element->getValue();
    }
    return sum;
}

int main() {
    vector<ListElement*> list;
    list.push_back(new IntegerElement(5));
    list.push_back(new IntegerElement(3));
    list.push_back(new IntegerElement(8));

    int sum = sumListElements(list);

    cout << "Sum of list elements: " << sum << endl;

    // Release memory
    for (ListElement* element : list) {
        delete element;
    }

    return 0;
}
