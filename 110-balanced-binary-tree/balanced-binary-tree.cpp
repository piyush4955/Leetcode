class Solution {
public:
    int getHeight(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftHeight = getHeight(root->left);
        if (leftHeight == -1) return -1;

        int rightHeight = getHeight(root->right);
        if (rightHeight == -1) return -1;

        if (abs(leftHeight - rightHeight) > 1) return -1;

        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }
};