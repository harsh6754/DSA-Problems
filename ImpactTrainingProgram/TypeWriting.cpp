#include <iostream>
#include <string>

using namespace std;

// Abstract class representing operations on a string
class StringOperator {
public:
    virtual ~StringOperator() = default;

    virtual void execute(string& str) = 0;
};

// Concrete classes for specific operations
class WriteOperator : public StringOperator {
public:
    void execute(string& str) override {
        // Implement write logic here
        str += "w";  // Example implementation
    }
};

class DeleteOperator : public StringOperator {
public:
    DeleteOperator(int n) : n_to_delete(n) {}

    void execute(string& str) override {
        // Implement delete logic here
        for (int i = 0; i < n_to_delete && !str.empty(); ++i) {
            str.pop_back();
        }
    }

private:
    int n_to_delete;
};

class UndoOperator : public StringOperator {
public:
    UndoOperator(int n_to_undo) : n_to_undo(n_to_undo) {}

    void execute(string& str) override {
        // Implement undo logic here
        for (int i = 0; i < n_to_undo && !str.empty(); ++i) {
            str.pop_back();
        }
    }

private:
    int n_to_undo;
};

int main() {
    string str, opStr;
    int n;
    cin >> str >> opStr;
    cin >> n;

    vector<StringOperator*> operators;

    for (char op : opStr) {
        switch (op) {
            case 'w':
                operators.push_back(new WriteOperator());
                break;
            case 'd':
                operators.push_back(new DeleteOperator(n));
                break;
            case 'u':
                operators.push_back(new UndoOperator(n));
                break;
        }
    }

    for (StringOperator* op : operators) {
        op->execute(str);
        delete op; // Release memory
    }

    cout << str << endl;

    return 0;
}
