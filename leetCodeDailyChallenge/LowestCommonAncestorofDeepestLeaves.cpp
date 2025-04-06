#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).second;
    }

private:
    // Helper function to return a pair of depth and the LCA node
    pair<int, TreeNode*> dfs(TreeNode* node) {
        if (!node) return {0, nullptr};

        auto left = dfs(node->left);
        auto right = dfs(node->right);

        if (left.first == right.first) {
            return {left.first + 1, node};
        } else if (left.first > right.first) {
            return {left.first + 1, left.second};
        } else {
            return {right.first + 1, right.second};
        }
    }
};

// Function to build a binary tree from a level-order array representation
TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != "null") {
            current->left = new TreeNode(stoi(nodes[i]));
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null") {
            current->right = new TreeNode(stoi(nodes[i]));
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Helper function to split a string by a delimiter
vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    cout << "Enter the tree in level-order format (e.g., [3,5,1,6,2,0,8,null,null,7,4]): ";
    string input;
    getline(cin, input);

    // Remove brackets and split the input
    input = input.substr(1, input.size() - 2);
    vector<string> nodes = split(input, ',');

    TreeNode* root = buildTree(nodes);

    Solution solution;
    TreeNode* lca = solution.lcaDeepestLeaves(root);

    if (lca) {
        cout << "The value of the lowest common ancestor of the deepest leaves is: " << lca->val << endl;
        cout << "The deepest leaves are: [";
        if (lca->left) cout << lca->left->val;
        if (lca->right) cout << "," << lca->right->val;
        cout << "]" << endl;
    } else {
        cout << "The tree is empty." << endl;
    }

    return 0;
}