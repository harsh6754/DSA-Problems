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
        this->right = NULL;
        this->left = NULL;
    }
};

Node *buildTree()
{
    cout << "Enter Root Node Value " << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *root = new Node(data);
    cout << "Enter Left Node Value : " << data << " ";
    root->left = buildTree();

    cout << "Enter Right Node Value : " << data << " ";
    root->right = buildTree();

    return root;
}

void levelOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node *>q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            Node* current = q.front();
            q.pop();
            if(i == size - 1) {
                cout << current->data << " ";
            }
            if(current->left){
                q.push(current->left);
            }
            if(current->right){
                q.push(current->right);
            }
        }
    }
}

void solve(Node* root, vector<int> &ans, int level ){
    if(root == NULL){
        return;
    }
    if(level == ans.size()){
        ans.push_back(root->data);
    }

    // Traverse right subtree before left subtree
    solve(root->right,ans,level + 1);
    solve(root->left, ans,level + 1);
}

vector<int>rightView(Node* root){
    vector<int>ans;
    solve(root,ans,0);
    return ans;
}

int main()
{
    Node *root = NULL;
    root = buildTree();

    cout << "Printing Level Order Traversal " << endl;
    levelOrderTraversal(root);
    cout << endl;

    vector<int>result = rightView(root);
    cout<<"Right View Element : "<<endl;
    for(int i = 0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;

    return 0;
}
