/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>vis;
        unordered_map<TreeNode*,TreeNode*>parent;
        vector<int>res;
        addparent(root,parent);
        if(root==NULL)return res;
        q.push(target);
        vis[target]=true;
        int level=0;
        while(!q.empty()){
            int n=q.size();
            if(level++==k)break;
            for(int i=0;i<n;i++){
                TreeNode* cur=q.front();
            q.pop();
                if(cur->left&&!vis[cur->left]){
                    vis[cur->left]=true;
                    q.push(cur->left);
                }
                if(cur->right&&!vis[cur->right]){
                    vis[cur->right]=true;
                    q.push(cur->right);
                }
                if(parent[cur]&&!vis[parent[cur]]){
                    vis[parent[cur]]=true;
                    q.push(parent[cur]);
                }
            }
        }
        while(!q.empty()){
            TreeNode* ans=q.front();q.pop();
            res.push_back(ans->val);
        }
        return res;
    }
    void addparent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent){
        if(root==NULL)return;
        if(root->left){
            parent[root->left]=root;
            addparent(root->left,parent);
        }
        if(root->right){
            parent[root->right]=root;
            addparent(root->right,parent);
        }
    }
};