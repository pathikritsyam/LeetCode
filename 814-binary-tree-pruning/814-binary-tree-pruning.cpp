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
    TreeNode* pruneTree(TreeNode* root) {
        if(dfs(root))return root;
        return NULL;
    }
    int dfs(TreeNode* root){
        if(!root)return false;
        bool left_1=dfs(root->left);
        bool right_1=dfs(root->right);
        if(!left_1)root->left=NULL;
        if(!right_1)root->right=NULL;
        return root->val+left_1+right_1;
    }
};