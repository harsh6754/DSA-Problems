#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root, int d) {
    if (root == NULL) {
        root = new Node(d); // Changed == to =
        return root;
    }

    if (d > root->data) {
        root->right = insertIntoBST(root->right, d); // Changed == to =
    } else {
        root->left = insertIntoBST(root->left, d); // Changed == to =
    }
    return root;
}

void takeInput(Node* &root) {
    int data;
    cin >> data;

    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        // Separator Logic
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder(Node *root){
    if(root == NULL)
        return;
    
    inorder(root->left);
    cout<<root->data<< " ";
    inorder(root->right);
}

void preorder(Node *root){
    if(root == NULL)
        return;
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root){
    if(root == NULL)
        return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<< " ";
}

int main() {
    Node* root = NULL;

    cout << "Enter Data in BST: ";
    takeInput(root);

    cout << "Printing Level Order Traversal: ";
    levelOrderTraversal(root);

    cout<<endl;
    cout<<"Inorder Traversal : ";
    inorder(root);
    cout<<endl;
    cout<<"Preorder Traversal : ";
    preorder(root);
    cout<<endl;
    cout<<"Postorder Traversal : ";
    postorder(root);


    return 0;
}
