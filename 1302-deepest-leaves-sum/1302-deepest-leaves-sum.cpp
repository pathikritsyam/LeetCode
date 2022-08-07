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
    int deepestLeavesSum(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        int sum=0,level=0,prev_level=-1;
        level=dfs(root);
        q.push({root,0});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            if(p.second==level)sum+=p.first->val;
            if(p.first->left)q.push({p.first->left,p.second+1});
            if(p.first->right)q.push({p.first->right,p.second+1});
        }
        return sum;
    }
    int dfs(TreeNode* root){
        if(!root)return 1;
        int left=0,right=0;
        if(root->left)left=1+dfs(root->left);
        if(root->right)right=1+dfs(root->right);
        return max(left,right);
    }
};
//7,8
//[50,null,54,98,6,null,null,null,34]