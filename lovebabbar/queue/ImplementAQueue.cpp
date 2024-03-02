#include <iostream>

using namespace std;

class Queue
{
    int size;
    int *arr;
    int myfront;
    int rare;

public:
    Queue(int size = 5000)
    {
        this->size = size;
        this->arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
        myfront = 0;
        rare = 0;
    }

    bool isEmpty()
    {
        if (myfront == rare)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int data)
    {
        if (rare < size)
        {
            arr[rare] = data;
            rare++;
        }
    }

    int dequeue()
    {
        if (myfront < size && myfront < rare)
        {
            int store = arr[myfront];
            arr[myfront] = 0;
            myfront++;
            return store;
        }
        else
        {
            return -1;
        }
    }

    int front()
    {
        if (myfront < rare)
        {
            return arr[myfront];
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;
    Queue q(size);
    int choice, data;
    do
    {
        cout << "Enter your choice:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Check if the queue is empty\n";
        cout << "5. Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter data to enqueue: ";
            cin >> data;
            q.enqueue(data);
            break;
        case 2:
            data = q.dequeue();
            if (data != -1)
                cout << "Dequeued element: " << data << endl;
            else
                cout << "Queue is empty\n";
            break;
        case 3:
            data = q.front();
            if (data != -1)
                cout << "Front element: " << data << endl;
            else
                cout << "Queue is empty\n";
            break;
        case 4:
            if (q.isEmpty())
                cout << "Queue is empty\n";
            else
                cout << "Queue is not empty\n";
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 5);

    return 0;
}
