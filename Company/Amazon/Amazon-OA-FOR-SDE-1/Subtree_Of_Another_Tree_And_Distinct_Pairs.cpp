#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x),left(NULL),right(NULL){}
};
TreeNode* insertLevelOrder(int arr[], int i, int n){
    if(i >= n || arr[i] == -1){
        return NULL;
    }
    TreeNode* root = new TreeNode(arr[i]);
    root->left = insertLevelOrder(arr,2*i+1,n);
    root->right = insertLevelOrder(arr,2*i+2,n);
    return root;
}
bool isSameTree(TreeNode* s,TreeNode* t){
    if(!s && !t){
        return true;
    }
    if(!s || !t || s->val != t->val){
        return false;
    }
    return isSameTree(s->left,t->left) && isSameTree(s->right,t->right);
}
bool isSubtree(TreeNode* s,TreeNode* t){
    if(!s){
        return false;
    }
    return isSameTree(s,t) || isSubtree(s->left,t) || isSubtree(s->right,t);
}
int main(){
    int n,m;
    cin>>n,m;

    int rootArr[n];
    for(int i = 0;i<n;i++){
        cin>>rootArr[i];
    }

    cin>>m;
    int subRootArr[m];
    for(int i = 0;i<m;i++){
        cin>>subRootArr[i];
    }

    TreeNode *root = insertLevelOrder(rootArr,0,n);
    TreeNode *subRoot = insertLevelOrder(subRootArr,0,m);

    cout << (isSubtree(root,subRoot)?"true":"false") << endl;
    return 0;
}