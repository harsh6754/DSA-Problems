#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(){
    int data;
    cout<<"Enter Root Node Value : ";
    cin>>data;

    if(data == -1 ){
        return NULL;
    }

    node *root = new node(data);
    cout<<"Enter Left Child Node Value "<<data<<endl;
    root->left = buildTree();

    cout<<"Enter the Right Child Node Value "<<data<<endl;
    root->right = buildTree();

    return root;
}

void levelOrderTraversal(node* root){
    if(root == NULL){
        return;
    }

    queue<node *>q;
    q.push(root);

    while(!q.empty()){
        node* current = q.front();
        cout<<current->data<<" ";

        if (current->left)
            q.push(current->left);

        if (current->right)
            q.push(current->right);

        q.pop();
    }
}

vector<int> verticalOrder(node* root) {
    map<int, map<int, vector<int>>> nodes;
    queue<pair<node*, pair<int, int>>> q;

    vector<int> ans;
    if (root == NULL) {
        return ans;
    }

    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty()) {
        pair<node*, pair<int, int>> temp = q.front();
        q.pop();
        node *frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode->data);

        if (frontNode->left) {
            q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
        }

        if (frontNode->right) {
            q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
        }
    }

    // populate the vector with unique values
    for (auto i : nodes) {
        for (auto j : i.second) {
            for (auto k : j.second) {
                ans.push_back(k);
            }
        }
    }

    return ans;
}

int main(){
    node* root = NULL;
    root = buildTree();

    cout<<"Print Level Oreder Traversal : "<<endl;;
    levelOrderTraversal(root);

    vector<int>result = verticalOrder(root);
    cout<<"Vertical Trversal : "<<endl;
    for(int i = 0;i<result.size();i++){
        cout<<result[i]<< " ";
    }
    cout<<endl;


    return 0;
}