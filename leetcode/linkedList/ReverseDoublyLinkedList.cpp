#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;
    
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void reverse() {
        Node* current = head;
        Node* temp = nullptr;

        while (current != nullptr) {
            // Swap next and prev pointers of the current node
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;

            // Move to the next node
            current = current->prev;
        }

        // Update head and tail
        if (temp != nullptr) {
            head = temp->prev;
        }
    }
};

int main() {
    DoublyLinkedList dll;
    int n, val;

    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> val;
        dll.insert(val);
    }

    std::cout << "Original list: ";
    dll.display();

    dll.reverse();

    std::cout << "Reversed list: ";
    dll.display();

    return 0;
}
