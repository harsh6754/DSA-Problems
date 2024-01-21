#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class RandomizedCollection {
public:
    int n;
    vector<int> v;
    unordered_map<int, vector<int> > mp;
    RandomizedCollection() {
        n=0;
        v.clear();
        mp.clear();
    }
    
    bool insert(int val) {
        v.push_back(val);
        mp[val].push_back(n++);
        return mp[val].size()<2;
        
    }
    
    bool remove(int val) {
        if(mp[val].size()==0)return false;
        int index = mp[val][mp[val].size()-1];
        mp[val].pop_back();
        v[index]=v[n-1];
        v.pop_back();
        n--;
        if(n>index){ mp[v[index]][mp[v[index]].size()-1]=index;sort(mp[v[index]].begin(), mp[v[index]].end());}
        return true;
    }
    
    int getRandom() {
        int index = rand()%n;
        return v[index];
    }
};


int main() {
    RandomizedCollection* obj = new RandomizedCollection();

    int choice, val;
    do {
        cout << "1. Insert\n2. Remove\n3. Get Random\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Insert result: " << (obj->insert(val) ? "true" : "false") << endl;
                break;

            case 2:
                cout << "Enter value to remove: ";
                cin >> val;
                cout << "Remove result: " << (obj->remove(val) ? "true" : "false") << endl;
                break;

            case 3:
                cout << "Random element: " << obj->getRandom() << endl;
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 4);

    delete obj;

    return 0;
}
