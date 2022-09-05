/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        if(!root)return ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>t;
            int n=q.size();
            for(int i=0;i<n;i++){
                Node* cur=q.front();
                q.pop();
                t.push_back(cur->val);
                for(auto j:cur->children){
                    q.push(j);
                }
            }
            ans.push_back(t);
        }
        return ans;
    }
};