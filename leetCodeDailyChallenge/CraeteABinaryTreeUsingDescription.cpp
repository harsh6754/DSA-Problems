#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
{
    unordered_map<int, TreeNode *> nodes;
    unordered_set<int> children;

    for (const auto &desc : descriptions)
    {
        int parent = desc[0];
        int child = desc[1];
        bool isLeft = desc[2];

        if (nodes.find(parent) == nodes.end())
        {
            nodes[parent] = new TreeNode(parent);
        }
        if (nodes.find(child) == nodes.end())
        {
            nodes[child] = new TreeNode(child);
        }

        if (isLeft)
        {
            nodes[parent]->left = nodes[child];
        }
        else
        {
            nodes[parent]->right = nodes[child];
        }
        children.insert(child);
    }
    for (const auto &desc : descriptions)
    {
        int parent = desc[0];
        if (children.find(parent) == children.end())
        {
            return nodes[parent];
        }
    }

    return nullptr;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> descriptions(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> descriptions[i][0] >> descriptions[i][1] >> descriptions[i][2];
    }
    TreeNode *root = createBinaryTree(descriptions);
    if (root)
    {
        cout << root->val << endl;
    }
    else
    {
        cout << endl;
    }
    return 0;
}