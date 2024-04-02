#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(){
    int data;
    cout<<"Enter Root Node Value :"<<endl;
    cin>>data;

    if(data == -1){
        return NULL;
    }

    Node *root = new Node(data);
    cout<<"Enter Left Children Node Value :"<<data<<" ";
    root->left = buildTree();

    cout<<"Enter Right Children Node Value :"<<data<<" ";
    root->right = buildTree();

    return root;
}

vector<int> zigZagTraversal(Node* root) {
    vector<int> res;
    if (root == NULL)
        return res;

    queue<Node*> q;
    bool dir = true;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        vector<int> temp;

        for (int i = 0; i < n; i++) {
            Node* curr = q.front();
            q.pop();
            temp.push_back(curr->data);

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }

        if (!dir)
            reverse(temp.begin(), temp.end());

        for (int i = 0; i < temp.size(); i++)
            res.push_back(temp[i]);

        dir = !dir;
    }

    return res;
}

int main() {
    Node* root = NULL;
    cout << "Enter the values for the binary tree (-1 for NULL):" << endl;
    root = buildTree();

    vector<int> result = zigZagTraversal(root);
    cout << "Zigzag Traversal: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
