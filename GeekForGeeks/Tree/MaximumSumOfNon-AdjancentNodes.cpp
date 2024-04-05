#include <iostream>
#include <queue>
#include <unordered_map>
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
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree()
{
    int data;
    cout << "Enter Node Value (-1 for NULL): ";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *root = new Node(data);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

void levelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left)
        {
            q.push(current->left);
        }
        if (current->right)
        {
            q.push(current->right);
        }
    }
}

class Solution
{
public:
    unordered_map<Node *, int> m;

    int getMaxSum(Node *root)
    {
        if (root == NULL)
        {
            return 0; // Modified: Return 0 for NULL node
        }

        if (m.find(root) != m.end()) // Modified: Check if already computed
            return m[root];
        
        int withNode = root->data;

        if (root->left)
        {
            withNode += getMaxSum(root->left->left);
            withNode += getMaxSum(root->left->right);
        }

        if (root->right)
        {
            withNode += getMaxSum(root->right->left);
            withNode += getMaxSum(root->right->right);
        }

        int withoutNode = getMaxSum(root->left) + getMaxSum(root->right);
        return m[root] = max(withNode, withoutNode);
    }
}; // Added missing semicolon

int main()
{
    Node *root = NULL;
    root = buildTree();

    cout << "Level Order Traversal: ";
    levelOrderTraversal(root);
    cout << endl;

    Solution solution;
    int result = solution.getMaxSum(root);
    cout << "Maximum Sum: " << result << endl;

    return 0;
}
