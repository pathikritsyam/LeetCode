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
    int maxi=-1e9;
    int maxPathSum(TreeNode* root) {
        height(root);
        return maxi;
    }
    int height(TreeNode* root){
        if(root==NULL)return 0;
        int lh=max(0,height(root->left));
        int rh=max(0,height(root->right));
        maxi=max(maxi,lh+rh+root->val);
        return root->val+max(lh,rh);
    }
};