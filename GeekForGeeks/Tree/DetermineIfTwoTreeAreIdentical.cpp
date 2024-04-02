#include<bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// Function to build a binary tree recursively
node* buildTree() {
    int data;
    cout << "Enter the Root Node Value : " << endl;
    cin >> data;

    if (data == -1) return NULL;

    node* root = new node(data);
    cout << "Enter the Left Child Value of " << data << ": " << endl;
    root->left = buildTree();
    cout << "Enter the Right Child Value of " << data << ": " << endl;
    root->right = buildTree();

    return root;
}

// Function for level order traversal of a binary tree
void levelOrderTraversal(node* root) {
    if (root == NULL)
        return;

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* current = q.front();
        cout << current->data << " ";

        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);

        q.pop();
    }
}

bool isIdentical(node* root1, node* root2) {
    // If both trees are empty, they are identical
    if (root1 == NULL && root2 == NULL)
        return true;
    
    // If one tree is empty and the other is not, they are not identical
    if (root1 == NULL || root2 == NULL)
        return false;
    
    // Check if the current nodes are equal and recursively check their subtrees
    return (root1->data == root2->data) && 
           isIdentical(root1->left, root2->left) && 
           isIdentical(root1->right, root2->right);
}

int main() {
    node* root1 = NULL;
    cout << "Enter Tree 1:\n";
    root1 = buildTree();

    node* root2 = NULL;
    cout << "Enter Tree 2:\n";
    root2 = buildTree();

    cout << "Printing Level Order Traversal of Tree 1: ";
    levelOrderTraversal(root1);
    cout << endl;

    cout << "Printing Level Order Traversal of Tree 2: ";
    levelOrderTraversal(root2);
    cout << endl;

    if (isIdentical(root1, root2))
        cout << "The trees are identical." << endl;
    else
        cout << "The trees are not identical." << endl;

    return 0;
}
