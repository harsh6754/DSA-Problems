#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root, int d){
    if(root == NULL){
        root =  new Node(d);
        return root;
    }

    if(d > root->data){
        root->right = insertIntoBST(root->right, d);
    }
    else if(d < root->data){
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

void takeInput(Node *&root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root,data);
        cin>>data;
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

Node* findMin(Node* node) {
    Node* current = node;

    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int main(){
    Node* root = NULL;
    cout<<"Enter Data to Insert into BST (-1 to stop): "<<endl;
    takeInput(root);

    cout << "Printing Level Order Traversal: ";
    levelOrderTraversal(root);
    cout<<endl;

    cout<<"Inorder Traversal : ";
    inorder(root);
    cout << endl;

    int key;
    cout << "Enter the node value to delete: ";
    cin >> key;
    root = deleteNode(root, key);

    cout << "BST after deleting " << key << ": ";
    levelOrderTraversal(root);
    cout<<endl;

    return 0;
}
