#include<bits/stdc++.h>
using namespace std;

class BinaryTreeNode{
    public:
          int data;
          BinaryTreeNode *left;  
          BinaryTreeNode *right;  

          BinaryTreeNode(int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
          }

};

BinaryTreeNode* takeInput(){ 
    int data;
    cout<<"Enter root Data : "<<endl;
    cin>>data;

    if( data == -1){
        return NULL;
    }

    BinaryTreeNode* root = new BinaryTreeNode(data); 
    queue<BinaryTreeNode*> q;  
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode* front = q.front();
        q.pop();
        int left,right;
        cout<<"Enter left child of "<< front->data <<" : ";  
        cin>>left;
        if(left != -1){
            BinaryTreeNode* leftChild = new BinaryTreeNode(left); 
            front->left = leftChild;
            q.push(leftChild);
        }
        cout << "Enter right child of " << front->data << ": ";
        cin >> right;
        if (right != -1) {
            BinaryTreeNode* rightChild = new BinaryTreeNode(right);  
            front->right = rightChild;
            q.push(rightChild);
        }
    }
    return root;
}

 int getDepth(BinaryTreeNode *root) {
        if(root == NULL) {
            return 0;
        }
        int leftSubtreeDepth = getDepth(root->left);
        int rightSubtreeDepth = getDepth(root->right);
        return max(leftSubtreeDepth, rightSubtreeDepth) + 1;
    }

int diameterOfBinaryTree(BinaryTreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int leftSubtreeDiameter = diameterOfBinaryTree(root->left);
        int rightSubtreeDiameter = diameterOfBinaryTree(root->right);
        int diameter = getDepth(root->left) + getDepth(root->right);
        diameter = max(diameter, max(leftSubtreeDiameter, rightSubtreeDiameter));
        return diameter;
    }


int main(){
    BinaryTreeNode* root = takeInput(); 

    int BTDiameter = diameterOfBinaryTree(root); 
    cout<<"Diameter of Binary Tree is "<< BTDiameter<<endl;
    
    delete root;
    return 0;
}
