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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newNode=new TreeNode(val);
            newNode->left=root;
            return newNode;
        }
        queue<TreeNode*>q;
        q.push(root);
        //BFS
        for(int i=1;i<depth-1;i++){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* top=q.front();
                q.pop();
                if(top->left)q.push(top->left);
                if(top->right)q.push(top->right);
            }
        }
        while(!q.empty()){
            TreeNode* temp=q.front()->left;
            q.front()->left=new TreeNode(val);
            q.front()->left->left=temp;
            temp=q.front()->right;
            q.front()->right=new TreeNode(val);
            q.front()->right->right=temp;
            q.pop();
        }
        return root;
    }
};