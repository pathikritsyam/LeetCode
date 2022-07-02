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
    int findBottomLeftValue(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        vector<int>res;
        q.push({root,0});
        int l=0;
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode* node=p.first;
            int level=p.second;
            if(level>l)l=level,res.clear();
            if(node->left)q.push({node->left,level+1});
            if(node->right)q.push({node->right,level+1});
            res.push_back(node->val);
        }
        return res[0];
    }
};