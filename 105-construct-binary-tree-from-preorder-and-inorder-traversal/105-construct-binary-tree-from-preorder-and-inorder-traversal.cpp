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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>inmap;
        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]]=i;
        }
        TreeNode* root=buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inmap);
        return root;
    }
    TreeNode* buildTree(vector<int>&preorder,int pstart,int pend,vector<int>&inorder,int instart,int inend,unordered_map<int,int>&inmap){
        if(pstart>pend||instart>inend)return NULL;
        TreeNode* root=new TreeNode(preorder[pstart]);
        int inRoot=inmap[root->val];
        int numsLeft=inRoot-instart;
        root->left=buildTree(preorder,pstart+1,pstart+numsLeft,inorder,instart,inRoot-1,inmap);
        root->right=buildTree(preorder,pstart+numsLeft+1,pend,inorder,inRoot+1,inend,inmap);
        return root;
    }
};
//3,9,20,15,7
//9,3,15,20,7