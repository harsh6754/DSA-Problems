#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree()
{
    cout << "Enter Root Node Value : " << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    node *root = new node(data);
    cout << "Enter the Left Child Node Value : " << data << " ";
    root->left = buildTree();

    cout << "Enter Right Child Node Value : " << data << " ";
    root->right = buildTree();

    return root;
}

void levelOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *current = q.front();
        cout << current->data << " ";

        if (current->left)
        {
            q.push(current->left);
        }
        if (current->right)
        {
            q.push(current->right);
        }

        q.pop();
    }
}

vector<int> topView(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    map<int, int> TopNode;
    queue<pair<node *, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<node *, int> temp = q.front();
        q.pop();
        node *frontNode = temp.first;
        int hd = temp.second;

        if (TopNode.find(hd) == TopNode.end())
        {
            TopNode[hd] = frontNode->data;
        }

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }
    for (auto i : TopNode)
    {
        ans.push_back(i.second);
    }
    return ans;
}

int main()
{
    node *root = NULL;
    root = buildTree();

    cout << "Printing Level Order Traversal : " << endl;
    levelOrderTraversal(root);
    cout << endl;

    vector<int> result = topView(root);
    cout << "Top View Element : " << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}