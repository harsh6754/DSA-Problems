#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

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
Node *minValue(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node* maxValue(Node* root){
    Node* temp = root;
    while(temp->right != NULL){
        temp= temp->right;
    }
    return temp;
}

int main()
{
    Node *root = NULL;
    cout << "Enter Data in BST";
    root = takeInput(root);
    cout << endl;

    cout<<"MinValue in BST is : "<<minValue(root) -> data<<endl;
    cout<<"MaxValue in BST is : "<<maxValue(root) -> data<<endl;

    return 0;
}