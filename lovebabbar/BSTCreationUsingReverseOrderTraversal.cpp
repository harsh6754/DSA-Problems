#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree()
{
    cout << "Enter Root Node Data" << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    node *root = new node(data);
    cout << "Enter the Data for Left Children of " << data << endl;
    root->left = buildTree();

    cout << "Enter the Data for Right Children of " << data << endl;
    root->right = buildTree();

    return root;
}

void levelOrderTraversal(node *root)
{
    if (root == NULL)
        return;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *current = q.front();
        cout << current->data << " ";
        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
        q.pop();
    }
}

void reverseLevelOrderTraversal(node *root)
{
    if (root == NULL)
        return;

    stack<node *> s;
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *current = q.front();
        s.push(current);
        if (current->right)
            q.push(current->right);
        if (current->left)
            q.push(current->left);
        q.pop();
    }

    while (!s.empty())
    {
        node *current = s.top();
        cout << current->data << " ";
        s.pop();
    }
}

int main()
{
    node *root = NULL;
    root = buildTree();

    cout << "Tree Printing (Level Order Traversal): " << endl;
    levelOrderTraversal(root);
    cout << endl;

    cout << "Tree Printing (Reverse Level Order Traversal): " << endl;
    reverseLevelOrderTraversal(root);
    cout << endl;

    return 0;
}
