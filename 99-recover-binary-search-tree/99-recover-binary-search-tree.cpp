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
    void recoverTree(TreeNode* root) {
        vector<int>tree;
        inorder(root,tree);
        pair<int,int> node=swappedNodes(tree);
        traverseTree(root,node.first,node.second,2);
    }
    void inorder(TreeNode* root,vector<int>&tree){
        if(root==NULL)return;
        inorder(root->left,tree);
        tree.push_back(root->val);
        inorder(root->right,tree);
    }
    pair<int,int> swappedNodes(vector<int>&tree){
        int x=-1,y=-1;
        bool flag=false;
        for(int i=1;i<tree.size();i++){
            if(tree[i]<tree[i-1]){
                x=tree[i];
                if(!flag){
                    y=tree[i-1];
                    flag=true;
                }
                else{
                    break;
                }
            }
        }
        return {x,y};
    }
    void traverseTree(TreeNode *root,int x,int y,int count){
        if(root==NULL)return;
        if(root->val==x||root->val==y){
            root->val=root->val==x?y:x;
            if(--count==0)return;
        }
        traverseTree(root->left,x,y,count);
        traverseTree(root->right,x,y,count);
    }
};
// 3 2 1 4
//y=1
//x=3