#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Solution {
public:
    Node* buildTree(int in[], int pre[], int n) {
        if (n == 0)
            return nullptr;

        Node* root = new Node(pre[0]);
        auto it = find(in, in + n, pre[0]);
        int idx = distance(in, it);
        
        root->left = buildTree(in, pre + 1, idx);
        root->right = buildTree(in + idx + 1, pre + idx + 1, n - idx - 1);
        
        return root;
    }
};

void printPostorder(Node* root) {
    if (root) {
        printPostorder(root->left);
        printPostorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Solution solution;
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    int in[n];
    int pre[n];
    
    cout << "Enter the inorder traversal: ";
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }

    cout << "Enter the preorder traversal: ";
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }

    Node* root = solution.buildTree(in, pre, n);

    cout << "Postorder traversal: ";
    printPostorder(root);
    cout << endl;

    return 0;
}
