#include <iostream>
#include <queue>
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

node* buildTree() {
    cout << "Enter the root node data: ";
    int data;
    cin >> data;
    if (data == -1)
        return NULL;

    node* root = new node(data);
    cout << "Enter the data for Left Child of " << data << ": ";
    root->left = buildTree();
    cout << "Enter the data for Right Child of " << data << ": ";
    root->right = buildTree();

    return root;
}

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

int main() {
    node* root = NULL;
    root = buildTree();

    cout << "Tree Printing (Level Order Traversal):" << endl;
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}
