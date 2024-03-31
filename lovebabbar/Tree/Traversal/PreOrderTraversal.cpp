//NLR -> Node Left Right

 #include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node *right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node *buildTree(){
    cout<<"Enter the Root/Node Data : "<<endl;
    int data;
    cin>>data;

    if(data == -1)
        return NULL;
    
    node *root = new node(data);
    cout<<"Enter Left Children Node Value : "<<data<<endl;
    root->left = buildTree();
    cout<<"Enter Right Children Node Value : "<<data<<endl;
    root->right = buildTree();

    return root;
}
void levelOrderTraversal(node* root){
    if(root == NULL)
        return;
    
    queue<node *>q;
    q.push(root);

    while(!q.empty()){
        node* current = q.front();
        cout<< current->data << " ";

        if(current->left)
            q.push(current->left);
        if(current->right)
            q.push(current->right);
        q.pop();
        
    }
}

void preorder(node *root){
    if(root == NULL)
        return;
    
    cout<<root->data<< " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    node* root = NULL;
    root = buildTree();

    cout<<"Printing Level Order Traversal : "<<endl;
    levelOrderTraversal(root);
    cout<<endl;


    cout<<"PreOrder Traversal is : "<<endl;
    preorder(root);

    return 0;
}