#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* buildTree() {
    cout << "Enter Node Value (-1 for NULL): ";
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    TreeNode *root = new TreeNode(data);

    cout << "Enter Left Child Node Value of " << data << " : ";
    root->left = buildTree();

    cout << "Enter Right Child Node Value of " << data << " : ";
    root->right = buildTree();

    return root;
}

void levelOrderTraversal(TreeNode *root) {
    if (root == NULL) {
        return;
    }

    queue<TreeNode *> q;
    q.push(root);

    cout << "Level Order Traversal: ";
    while (!q.empty()) {
        TreeNode *current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left) {
            q.push(current->left);
        }
        if (current->right) {
            q.push(current->right);
        }
    }
    cout << endl;
}

void findPaths(TreeNode* root, int target, vector<int>& path, int& count) {
    if (!root)
        return;

    path.push_back(root->data);

    findPaths(root->left, target, path, count);
    findPaths(root->right, target, path, count);

    int sum = 0;
    for (int i = path.size() - 1; i >= 0; --i) {
        sum += path[i];
        if (sum == target)
            ++count;
    }
       path.pop_back();
}

int countPathsWithSum(TreeNode* root, int target) {
    vector<int> path;
    int count = 0;
    findPaths(root, target, path, count);
    return count;
}

int main() {
    TreeNode *root = NULL;
    root = buildTree();

    levelOrderTraversal(root);

    int k;
    cout << "Enter the target sum value (k): ";
    cin >> k;
    int result = countPathsWithSum(root, k);
    cout << "Number of paths with sum " << k << ": " << result << endl;

    return 0;
}
