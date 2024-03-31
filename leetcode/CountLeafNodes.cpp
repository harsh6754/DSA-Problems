#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        delete left;
        delete right;
    }
};

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cout << "Enter root data: ";
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty()) {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int leftChildData, rightChildData;
        cout << "Enter left child of " << front->data << ": ";
        cin >> leftChildData;
        if (leftChildData != -1) {
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }
        cout << "Enter right child of " << front->data << ": ";
        cin >> rightChildData;
        if (rightChildData != -1) {
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rightChildData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}

int noOfLeafNodes(BinaryTreeNode<int> *root){
    if(root==NULL){
        return 0;
    }
    if(!root->left && !root->right){
        return 1;
    }
    return (noOfLeafNodes(root->left) + noOfLeafNodes(root->right));
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int leafNodes = noOfLeafNodes(root);
    cout << "Number of leaf nodes: " << leafNodes << endl;
    delete root;
    return 0;
}
