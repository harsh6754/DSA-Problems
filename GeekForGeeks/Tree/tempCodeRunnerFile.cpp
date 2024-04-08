int maxTimeToBurnTree(Node* root, int target, unordered_map<Node*, Node*>& parent, int &time) {
        if (root == NULL) return 0;
        
        if (root->data == target) {
            if (root->left) {
                parent[root->left] = root;
                maxTimeToBurnTree(root->left, target, parent, time);
                time++;
            }
            if (root->right) {
                parent[root->right] = root;
                maxTimeToBurnTree(root->right, target, parent, time);
                time++;
            }
            return 1;
        }
        
        int left = maxTimeToBurnTree(root->left, target, parent, time);
        int right = maxTimeToBurnTree(root->right, target, parent, time);
        
        if (left > 0 || right > 0) {
            time++;
            return 1 + max(left, right);
        }
        
        return 0;
    }