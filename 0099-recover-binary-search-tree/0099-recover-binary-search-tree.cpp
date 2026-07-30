/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private: 
    TreeNode* prev;
    TreeNode* first;
    TreeNode* second;
    TreeNode* middle;

public:

    void inorder(TreeNode* root) {
        if(root==NULL) return;

        inorder(root->left);

        if(prev!=NULL && (root->val < prev->val)) {
            if(first==NULL) {
                first=prev;
                middle=root;
            }
            else {
                second=root;
            }
        }
        prev=root;
        inorder(root->right);
        // return root;
    }
    void recoverTree(TreeNode* root) {
        first=middle=second=NULL;
        inorder(root);

        if(first && second) swap(first->val,second->val);
        else if(first && middle){
            swap(first->val,middle->val);
        }
        // return root;
    }
};