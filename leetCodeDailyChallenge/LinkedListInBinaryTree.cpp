#include <iostream>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!head) return true;
        if (!root) return false;

        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }

private:
    bool dfs(ListNode* head, TreeNode* root) {
        if (!head) return true;
        if (!root) return false;

        if (head->val != root->val) return false;

        return dfs(head->next, root->left) || dfs(head->next, root->right);
    }
};

ListNode* createLinkedList() {
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    if (n == 0) return nullptr;

    cout << "Enter the values of the linked list nodes: ";
    int val;
    cin >> val;
    ListNode* head = new ListNode(val);
    ListNode* current = head;

    for (int i = 1; i < n; ++i) {
        cin >> val;
        current->next = new ListNode(val);
        current = current->next;
    }

    return head;
}

TreeNode* createBinaryTree() {
    int n;
    cout << "Enter the number of nodes in the binary tree: ";
    cin >> n;

    if (n == 0) return nullptr;

    cout << "Enter the values of the binary tree nodes (use -1 for null nodes): ";
    int val;
    cin >> val;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    for (int i = 1; i < n; ++i) {
        TreeNode* current = q.front();
        q.pop();

        cin >> val;
        if (val != -1) {
            current->left = new TreeNode(val);
            q.push(current->left);
        }

        if (++i >= n) break;

        cin >> val;
        if (val != -1) {
            current->right = new TreeNode(val);
            q.push(current->right);
        }
    }

    return root;
}

int main() {
    ListNode* head = createLinkedList();
    TreeNode* root = createBinaryTree();

    Solution solution;
    bool result = solution.isSubPath(head, root);

    if (result) {
        cout << "The linked list is a subpath of the binary tree." << endl;
    } else {
        cout << "The linked list is NOT a subpath of the binary tree." << endl;
    }

    return 0;
}
