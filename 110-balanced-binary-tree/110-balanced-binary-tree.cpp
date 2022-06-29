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
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        int lh=height(root->left);
        int rh=height(root->right);
        if(abs(lh-rh)>1)return false;
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        return !(!left||!right);
        return true;
    }
    int height(TreeNode* root){
        if(root==NULL)return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        return 1+max(lh,rh);
    }
};