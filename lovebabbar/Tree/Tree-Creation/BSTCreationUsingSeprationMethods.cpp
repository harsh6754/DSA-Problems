#include <bits/stdc++.h>
using namespace std;
// BST CREATION
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

node *buildTree(node *root)
{
    cout << "Enter The Data: " << endl;
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new node(data);

    cout << "Enter Data for Left Child of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter Data for Right Child of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

// Level Order Traversal(BFS)
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        // Separator Logic
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    node *root = NULL;
    root = buildTree(root);

    // levelOrderTraversal
    cout << "Tree Printing" << endl;
    levelOrderTraversal(root);
    return 0;
}
