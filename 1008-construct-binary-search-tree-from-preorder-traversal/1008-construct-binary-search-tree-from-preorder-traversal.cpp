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
    int idx,n;
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int l=-1e9,r=1e9;
        idx=0;
        n=preorder.size();
        return f(l,r,preorder);
    }
    TreeNode* f(int l,int r,vector<int>&preorder){
        if(idx==n)return NULL;
        int val=preorder[idx];
        if(val<l||val>r)return NULL;
        idx++;
        TreeNode* root=new TreeNode(val);
        root->left=f(l,val,preorder);
        root->right=f(val,r,preorder);
        return root;
    }
};