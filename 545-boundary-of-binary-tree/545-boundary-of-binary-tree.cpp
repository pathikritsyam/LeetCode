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
    bool isleaf(TreeNode* root){
            return !root->left && !root->right;
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int>res;
        if(root==NULL)return res;
        if(!isleaf(root))res.push_back(root->val);
        addLeftBoundary(root,res);//traverse left boundary
        addLeaves(root,res);//traverse leaf nodes
        addRightBoundary(root,res);//traverse right boundary
        return res;
    }
    void addLeftBoundary(TreeNode* root,vector<int>&res){
        TreeNode* cur=root->left;
        while(cur){
            if(!isleaf(cur))res.push_back(cur->val);
            if(cur->left)cur=cur->left;
            else cur=cur->right;
        }
    }
    void addRightBoundary(TreeNode* root,vector<int>&res){
        vector<int>tmp;
        TreeNode* cur=root->right;
        while(cur){
            if(!isleaf(cur))tmp.push_back(cur->val);
            if(cur->right)cur=cur->right;
            else cur=cur->left;
        }
        for(int i=tmp.size()-1;i>=0;i--)res.push_back(tmp[i]);
    }
    //pre-order traversal, inorder will also work just keep left node first
    void addLeaves(TreeNode* root,vector<int>&res){
        if(isleaf(root)){
            res.push_back(root->val);
            return;
        }
        if(root->left)addLeaves(root->left,res);
        if(root->right)addLeaves(root->right,res);
    }
};