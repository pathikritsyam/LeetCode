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
    int cnt=0;
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root,0);
        return cnt;
    }
    void dfs(TreeNode* node,int path){
        if(!node)return;
        path^=(1<<node->val);
        if(!node->left&&!node->right)
            if(!(path&(path-1)))
                cnt++;
        dfs(node->left,path);
        dfs(node->right,path);
    }
};