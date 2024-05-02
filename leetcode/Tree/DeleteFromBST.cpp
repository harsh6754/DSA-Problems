#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int data;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertIntoBST(Node *root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (d > root->data)
    {
        root->right = insertIntoBST(root->right, d);
    }
    else
    {
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

Node *takeInput(Node *root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
    return root;
}

Node *deleteFromBST(Node *root, int target)
{
    if (root == NULL)
    {
        return root;
    }
    if (target < root->data)
    {
        root->left = deleteFromBST(root->left, target);
    }
    else if (target > root->data)
    {
        root->right = deleteFromBST(root->right, target);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        Node *succParent = root;
        Node *succ = root->right;
        while (succ->left != NULL)
        {
            succParent = succ;
            succ = succ->left;
        }
        root->data = succ->data;

        if (succParent->left == succ)
        {
            succParent->left = succ->right;
        }
        else
        {
            succParent->right = succ->right;
        }
        delete succ;
    }
    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = NULL;
    cout << "Enter Data in BST (enter -1 to stop): ";
    root = takeInput(root);
    cout << endl;

    int target;
    cout << "Enter target to delete: ";
    cin >> target;

    cout << "Before Deleting the Element : ";
    inorder(root);
    cout << endl;

    root = deleteFromBST(root, target);

    cout << "After Deleting the Element : ";
    inorder(root);
    cout << endl;

    return 0;
}
