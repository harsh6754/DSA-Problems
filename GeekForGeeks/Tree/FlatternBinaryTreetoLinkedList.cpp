#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

Node* buildTree() {
    int data;
    cout << "Enter Node Value (-1 for NULL): ";
    cin >> data;

    if (data == -1) {
        return nullptr;
    }

    Node* root = new Node(data);
    cout << "Enter left Node Value for " << data << ": ";
    root->left = buildTree();

    cout << "Enter Right Node Value for " << data << ": ";
    root->right = buildTree();

    return root;
}

class Solution {
public:
    void flatten(Node* root) {
        if (root == nullptr)
            return;
        
        while (root != nullptr) {
            if (root->left != nullptr) {
                Node* prev = root->left;
                while (prev->right != nullptr)
                    prev = prev->right;
                
                prev->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right; 
        }
    };

    void printInOrder(Node* root) {
        if (root == nullptr)
            return;
        printInOrder(root->left);
        cout << root->data << " ";
        printInOrder(root->right);
    }
};

int main() {
    Node* root = nullptr;
    root = buildTree();

    Solution solution;
    solution.flatten(root);
    solution.printInOrder(root);

    return 0;
}
