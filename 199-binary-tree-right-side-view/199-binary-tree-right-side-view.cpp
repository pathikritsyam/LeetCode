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
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        vector<int>res;
        vector<int>ans;
        if(root==NULL)return ans;
        q.push({root,0});
        int l=0;
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode* node=p.first;
            int level=p.second;
            if(level>l)ans.push_back(res.back()),l=level,res.clear();
            if(node->left)q.push({node->left,level+1});
            if(node->right)q.push({node->right,level+1});
            res.push_back(node->val);
        }
        ans.push_back(res.back());
        return ans;
    }
};