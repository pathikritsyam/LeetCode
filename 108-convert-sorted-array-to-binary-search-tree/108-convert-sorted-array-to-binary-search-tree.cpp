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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return f(0,n-1,nums);
    }
    TreeNode* f(int i,int j,vector<int>&nums){
        if(i>j)return NULL;
        int mid=(i+j)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=f(i,mid-1,nums);
        root->right=f(mid+1,j,nums);
        return root;
    }
};