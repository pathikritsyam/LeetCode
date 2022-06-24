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
    int f(TreeNode* root,unordered_map<TreeNode*,int>&dp){
        if(root==NULL)return 0;
        if(dp.find(root)!=dp.end())return dp[root];
        int including_root=root->val;
        if(root->left)including_root+=f(root->left->left,dp)+f(root->left->right,dp);
        if(root->right)including_root+=f(root->right->left,dp)+f(root->right->right,dp);
        int excluding_root=f(root->left,dp)+f(root->right,dp);
        return dp[root]=max(including_root,excluding_root);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int>dp;
        return f(root,dp);
    }
};