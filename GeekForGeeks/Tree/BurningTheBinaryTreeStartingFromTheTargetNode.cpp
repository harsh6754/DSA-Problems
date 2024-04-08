#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    struct Node *left, *right;
};
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return (temp);
}
 
int burnTreeUtil(Node* root, int target, queue<Node*>& q)
{
    if (root == NULL) {
        return 0;
    }

    if (root->key == target) {
        cout << root->key << endl;
        if (root->left != NULL) {
            q.push(root->left);
        }
        if (root->right != NULL) {
 
            q.push(root->right);
        }
        return 1;
    }
 
    int a = burnTreeUtil(root->left, target, q);
 
    if (a == 1) {
        int qsize = q.size();
        while (qsize--) {
            Node* temp = q.front();
            cout << temp->key << " , ";
            q.pop();
            if (temp->left != NULL)
                q.push(temp->left);
 
            if (temp->right != NULL)
                q.push(temp->right);
        }
 
        if (root->right != NULL)
            q.push(root->right);
 
        cout << root->key << endl;
        return 1;
    }
 
    int b = burnTreeUtil(root->right, target, q);
 
    if (b == 1) {
        int qsize = q.size();
 
        while (qsize--) {
            Node* temp = q.front();

            cout << temp->key << " , ";
            q.pop();

            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
 
        if (root->left != NULL)
            q.push(root->left);
 
        cout << root->key << endl;

        return 1;
    }
}
 
void burnTree(Node* root, int target)
{
    queue<Node*> q;

    burnTreeUtil(root, target, q);

    while (!q.empty()) {
        int qSize = q.size();
        while (qSize > 0) {
            Node* temp = q.front();

            cout << temp->key;
            if (temp->left != NULL) {
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                q.push(temp->right);
            }
 
            if (q.size() != 1)
                cout << " , ";
 
            q.pop();
            qSize--;
        }
        cout << endl;
    }
}

int main()
{ 
    Node* root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(13);
 
    root->right->left = newNode(14);
    root->right->right = newNode(15);
 
    root->right->left->left = newNode(21);
    root->right->left->right = newNode(22);
    root->right->right->left = newNode(23);
    root->right->right->right = newNode(24);
    int targetNode = 14;
 
    burnTree(root, targetNode);
 
    return 0;
}