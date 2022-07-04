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
    int maxLevelSum(TreeNode* root) {
        vector<int>res;
        int ans=-1e9,index;
        if(!root)return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        while(!q.empty()){
            int n=q.size();
            int temp=0,level;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front().first;
                level=q.front().second;
                q.pop();
                if(node->left)q.push({node->left,level+1});
                if(node->right)q.push({node->right,level+1});
                temp+=node->val;
            }
            if(temp>ans)ans=temp,index=level;
        }
        return index;
    }
};