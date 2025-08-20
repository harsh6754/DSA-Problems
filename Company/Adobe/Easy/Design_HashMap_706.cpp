#include<bits/stdc++.h>
using namespace std;

class MyHashMap {
    vector<list<pair<int,int>>> table;
    int size = 1000;
    
    int hashFunc(int key) {
        return key % size;
    }
    
public:
    MyHashMap() {
        table.resize(size);
    }
    
    void put(int key, int value) {
        int hash = hashFunc(key);
        for (auto &p : table[hash]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        table[hash].push_back({key, value});
    }
    
    int get(int key) {
        int hash = hashFunc(key);
        for (auto &p : table[hash]) {
            if (p.first == key) return p.second;
        }
        return -1;
    }
    
    void removeKey(int key) {
        int hash = hashFunc(key);
        for (auto it = table[hash].begin(); it != table[hash].end(); it++) {
            if (it->first == key) {
                table[hash].erase(it);
                return;
            }
        }
    }
};

int main() {
    MyHashMap myMap;
    int n;
    cout << "Enter number of operations: ";
    cin >> n;

    cout << "Enter operations (like put/get/remove) with values:\n";

    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;

        if (op == "put") {
            int key, value;
            cin >> key >> value;
            myMap.put(key, value);
            cout << "Inserted (" << key << ", " << value << ")\n";
        } 
        else if (op == "get") {
            int key;
            cin >> key;
            cout << "Value at key " << key << " = " << myMap.get(key) << "\n";
        } 
        else if (op == "remove") {
            int key;
            cin >> key;
            myMap.removeKey(key);
            cout << "Removed key " << key << "\n";
        } 
        else {
            cout << "Invalid operation\n";
        }
    }

    return 0;
}
