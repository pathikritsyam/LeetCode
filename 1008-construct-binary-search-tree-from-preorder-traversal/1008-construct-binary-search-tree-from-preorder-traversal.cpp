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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder=preorder;
        sort(inorder.begin(),inorder.end());
        unordered_map<int,int>inmap;
        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]]=i;
        }
        return bst(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,inmap);
    }
    TreeNode* bst(vector<int>&inorder,int istart,int iend,vector<int>&preorder,int pstart,int pend,unordered_map<int,int>&inmap){
        if(istart>iend||pstart>pend)return NULL;
        TreeNode* root=new TreeNode(preorder[pstart]);
        int iroot=inmap[root->val];
        int numleft=iroot-istart;
        root->left=bst(inorder,istart,iroot-1,preorder,pstart+1,pstart+numleft,inmap);
        root->right=bst(inorder,iroot+1,iend,preorder,pstart+numleft+1,pend,inmap);
        return root;
    }
};