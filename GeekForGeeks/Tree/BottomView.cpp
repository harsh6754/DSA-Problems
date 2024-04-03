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
    cout<<"Enter Root Node Value "<<endl;
    int data;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    node *root = new node(data);
    cout<<"Enter Left Child Node Value "<<data<< " ";
    root->left = buildTree();

    cout<<"Enter Right Child Node Value "<< data<<" ";
    root->right= buildTree();


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
        cout<<current->data<< " ";

        if(current->left){
            q.push(current->left);
        }
        if(current->right){
            q.push(current->right);
        }
        q.pop();
    }
}

vector<int>bottomView(node *root){
     vector<int>ans;
        if(root == NULL)
        {
            return ans;
        }
        map<int,int>m;
        
        queue<pair<node *,int>>q;
        q.push({root,0});
        
        while(!q.empty())
        {
            node* temp=q.front().first;
            int horidis=q.front().second;
            q.pop();
            
            m[horidis]=temp->data;
            
            if(temp->left)
            {
                q.push({temp->left,horidis-1});
            }
            if(temp->right)
            {
                q.push({temp->right,horidis+1});
            }
        }
        for(auto it: m)
        {
            ans.push_back(it.second);
            
        }
        return ans;
}

int main(){
    node *root = NULL;
    root = buildTree();


    cout<<"Printing Level Order Traversal : "<<endl;
    levelOrderTraversal(root);
    cout<<endl;


    vector<int> result = bottomView(root);
    cout<<"Bottom View Element ";
    for(int i = 0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;

    return 0;
}