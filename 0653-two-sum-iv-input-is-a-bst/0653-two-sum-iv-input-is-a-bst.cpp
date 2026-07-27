class Solution {
public:

    bool dfs(TreeNode* root, int a, TreeNode* b) {

        if(root == NULL)
            return false;

        if(root->val == a && root != b)
            return true;

        if(a < root->val)
            return dfs(root->left, a, b);

        return dfs(root->right, a, b);
    }

    bool helper(TreeNode* root, TreeNode* original, int k) {

        if(root == NULL)
            return false;

        int a = k - root->val;

        if(dfs(original, a, root))
            return true;

        return helper(root->left, original, k) ||
               helper(root->right, original, k);
    }

    bool findTarget(TreeNode* root, int k) {

        return helper(root, root, k);

    }
};