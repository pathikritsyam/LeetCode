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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>s1,s2;
        vector<int>postorder;
        if(root==NULL)return postorder;
        s1.push(root);
        while(!s1.empty()){
            root=s1.top();
            s1.pop();
            s2.push(root);
            if(root->left!=NULL)s1.push(root->left);
            if(root->right!=NULL)s1.push(root->right);
        }
        while(!s2.empty()){
            root=s2.top();
            s2.pop();
            postorder.push_back(root->val);
        }
        return postorder;
    }
};