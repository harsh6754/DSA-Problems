#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to sort people by height
vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    vector<pair<int, string>> people;
    int n = names.size();
    
    // Combine names and heights into a vector of pairs
    for (int i = 0; i < n; ++i) {
        people.push_back({heights[i], names[i]});
    }
    
    // Sort the vector of pairs by height in descending order
    sort(people.rbegin(), people.rend());
    
    // Extract the sorted names from the vector of pairs
    vector<string> sortedNames;
    for (int i = 0; i < n; ++i) {
        sortedNames.push_back(people[i].second);
    }
    
    return sortedNames;
}

int main() {
    int n;
    cout << "Enter the number of people: ";
    cin >> n;
    
    vector<string> names(n);
    vector<int> heights(n);
    
    // Taking input from the user
    for (int i = 0; i < n; ++i) {
        cout << "Enter name of person " << i + 1 << ": ";
        cin >> names[i];
        cout << "Enter height of person " << i + 1 << ": ";
        cin >> heights[i];
    }
    
    // Get the sorted names
    vector<string> sortedNames = sortPeople(names, heights);
    
    // Output the sorted names
    cout << "Sorted names by height in descending order:" << endl;
    for (const string& name : sortedNames) {
        cout << name << endl;
    }
    
    return 0;
}
