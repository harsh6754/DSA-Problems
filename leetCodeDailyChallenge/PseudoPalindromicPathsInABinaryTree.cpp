#include <iostream>
#include <stack>
#include <utility>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        int count = 0, path = 0;

        stack<pair<TreeNode*, int>> stk;
        stk.push(make_pair(root, 0));

        while (!stk.empty()) {
            pair<TreeNode*, int> current = stk.top();
            stk.pop();

            TreeNode* node = current.first;
            int currentPath = current.second;

            if (node != nullptr) {
                currentPath = currentPath ^ (1 << node->val);

                if (node->left == nullptr && node->right == nullptr) {
                    if ((currentPath & (currentPath - 1)) == 0) {
                        ++count;
                    }
                } else {
                    stk.push(make_pair(node->right, currentPath));
                    stk.push(make_pair(node->left, currentPath));
                }
            }
        }

        return count;
    }
};

int main() {
    int rootValue;
    cout << "Enter the value of the root node: ";
    cin >> rootValue;
    TreeNode* root = new TreeNode(rootValue);

    Solution solution;
    int result = solution.pseudoPalindromicPaths(root);
    cout << "Result: " << result << endl;

    // Free the allocated memory for the tree nodes
    // (You need to implement this part based on your tree construction logic)

    return 0;
}
