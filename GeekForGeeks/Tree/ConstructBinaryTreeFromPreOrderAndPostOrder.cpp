#include <iostream>
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
    int Find(int in[], int target, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (in[i] == target) return i;
        }
        return end - 1;
    }
    
    Node* Tree(int in[], int post[], int InStart, int InEnd, int index) {
        if (InStart > InEnd) return nullptr;
        
        Node* root = new Node(post[index]);
        int pos = Find(in, post[index], InStart, InEnd);
        
        // right
        root->right = Tree(in, post, pos + 1, InEnd, index - 1);
        // left 
        root->left = Tree(in, post, InStart, pos - 1, index - (InEnd - pos) - 1);
        
        return root;
    }
    
    Node* buildTree(int in[], int post[], int n) {
        return Tree(in, post, 0, n - 1, n - 1);
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
    int post[n];
    
    cout << "Enter the inorder traversal: ";
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }

    cout << "Enter the postorder traversal: ";
    for (int i = 0; i < n; i++) {
        cin >> post[i];
    }

    Node* root = solution.buildTree(in, post, n);

    cout << "Postorder traversal: ";
    printPostorder(root);
    cout << endl;

    return 0;
}
