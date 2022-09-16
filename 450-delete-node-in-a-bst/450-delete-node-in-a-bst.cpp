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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return root;
        if(root->val<key)root->right=deleteNode(root->right,key);
        else if(root->val>key)root->left=deleteNode(root->left,key);
        else{
            auto toDel=root;
            if(!root->left||!root->right)
                root=root->left?root->left:root->right;
            else{
                auto cur=root,par=root;
                root=root->right;
                while(root->left)par=root,root=root->left;
                cur->val=root->val;
                if(par->left==root)par->left=root->right;
                else par->right=root->right;
                toDel=root;
                root=cur;
            }
            delete toDel;
        }
        return root;
    }
};