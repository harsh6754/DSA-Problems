#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    vector<Node*> children;
    Node(int _val) : val(_val) {}
};

class Solution {
    pair<int, int> dfs(Node* root, double &maxAvg, Node* &maxNode) {
        if (!root) return {0, 0};
        
        int sum = root->val, count = 1;
        for (auto child : root->children) {
            pair<int, int> childResult = dfs(child, maxAvg, maxNode);
            sum += childResult.first;
            count += childResult.second;
        }
        
        if (count > 1) { 
            double avg = (double)sum / count;
            if (avg > maxAvg) {
                maxAvg = avg;
                maxNode = root;
            }
        }
        return {sum, count};
    }
    
public:
    Node* findSubtreeWithMaxAverage(Node* root) {
        if (!root) return nullptr;
        double maxAvg = INT_MIN;
        Node* maxNode = nullptr;
        dfs(root, maxAvg, maxNode);
        return maxNode;
    }
};

Node* buildTree() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    if (n == 0) return nullptr;
    
    unordered_map<int, Node*> nodes;
    for (int i = 0; i < n; i++) {
        int val;
        cout << "Enter node value: ";
        cin >> val;
        nodes[val] = new Node(val);
    }
    
    int edges;
    cout << "Enter number of edges: ";
    cin >> edges;
    
    Node* root = nullptr;
    unordered_set<int> childSet;
    
    for (int i = 0; i < edges; i++) {
        int parent, child;
        cout << "Enter parent and child values: ";
        cin >> parent >> child;
        nodes[parent]->children.push_back(nodes[child]);
        childSet.insert(child);
    }
    
    for (auto it = nodes.begin(); it != nodes.end(); ++it) {
        if (childSet.find(it->first) == childSet.end()) {
            root = it->second;
            break;
        }
    }
    
    return root;
}

int main() {
    Node* root = buildTree();
    Solution solution;
    Node* result = solution.findSubtreeWithMaxAverage(root);
    
    if (result)
        cout << "Subtree with maximum average root value: " << result->val << endl;
    else
        cout << "No valid subtree found." << endl;
    
    return 0;
}
