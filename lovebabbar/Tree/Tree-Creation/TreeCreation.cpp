#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* Left;
    Node* Right;
    int data;

    Node(int d){
        data = d;
        Left = NULL;
        Right = NULL;
    }
};

Node* buildTree(){
    cout<<"Enter the root Node Value";
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }
    Node* root = new Node(data);
    cout<<"Enter Left Root Node Value "<<data<<" : ";
    root->Left = buildTree();

    cout<<"Enter Right Root Node Value "<<data<<" : ";
    root->Right = buildTree();

    return root;
}

void levelOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);

   while (!q.empty()) {
        Node* current = q.front();
        cout << current->data << " ";
        if (current->Left)
            q.push(current->Left);
        if (current->Right)
            q.push(current->Right);
        q.pop();
    }
}
int main()
{
    Node* root = NULL;
    root = buildTree();
    cout<<"Printing Level Order Traversal "<<endl;
    levelOrderTraversal(root);

    cout<<endl;

    return 0;
}