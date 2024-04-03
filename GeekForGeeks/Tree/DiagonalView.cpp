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

vector<int> diagonal(Node* root) {
    vector<int> result;
    if (!root) return result;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        while (current) {
            result.push_back(current->data);
            if (current->left) q.push(current->left);
            current = current->right;
        }
    }

    return result;
}

int main()
{
    Node *root = NULL;
    root = buildTree();

    vector<int> result = diagonal(root);

    cout << "Diagonal View Elements: ";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
