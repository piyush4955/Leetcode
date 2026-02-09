class Solution {
public:
    void storeNodes(TreeNode* root, vector<TreeNode*>& nodes) {
        if (!root) return;
        storeNodes(root->left, nodes);
        nodes.push_back(root);
        storeNodes(root->right, nodes);
    }

    TreeNode* build(vector<TreeNode*>& nodes, int start, int end) {
        if (start > end) return nullptr;

        int mid = start + (end - start) / 2;
        TreeNode* root = nodes[mid];

        root->left = build(nodes, start, mid - 1);
        root->right = build(nodes, mid + 1, end);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        storeNodes(root, nodes);
        return build(nodes, 0, (int)nodes.size() - 1);
    }
};