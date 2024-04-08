#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution {
public:
int ans = 0;

 

int find(Node* root, int tar, int dis)

{

   if (root == NULL) {

      ans = max(ans, dis-1);

      return 0;

   }

 

   if (root->data == tar || dis > 0) {

      find(root->left, tar, dis+1);

      find(root->right, tar, dis+1);

      return dis-1;

   }

   else {

      int lft = find(root->left, tar, dis);

      int rgt = find(root->right, tar, dis);

      if (lft < 0) {

         ans = max(ans, -lft);

         find(root->right, tar, 1-lft);

         return lft-1;

      }

      if (rgt < 0) {

         ans = max(ans, -rgt);

         find(root->left, tar, 1-rgt);

         return rgt-1;

      }

   }

   

   return 0;

}

 

int minTime(Node* root, int target)

{

   find(root, target, 0);

   return ans;

}
};
Node *buildTree() {
    cout << "Enter Root Node Value : ";
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    Node *root = new Node(data);
    cout << "Enter Left Node Value for " << data << " : ";
    root->left = buildTree();

    cout << "Enter Right Node Value for " << data << " : ";
    root->right = buildTree();

    return root;
}

int main() {
    Node *root = NULL;
    root = buildTree();
    cout << endl;

    Solution solution;
    int target;
    cout << "Enter Target Node: ";
    cin >> target;

    int result = solution.minTime(root, target);
    cout << "Min Time To Burn Entire Tree : " << result << endl;

    return 0;
}
