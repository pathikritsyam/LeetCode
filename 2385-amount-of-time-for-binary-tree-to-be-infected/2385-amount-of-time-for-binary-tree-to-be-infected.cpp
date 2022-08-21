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
    unordered_map<int,vector<int>>graph;
    int amountOfTime(TreeNode* root, int start) {
        createGraph(root,-1);
        // for(auto node:graph){
        //     cout<<node.first<<"-";
        //     for(auto i:node.second){
        //         cout<<i<<" ";
        //     }
        //     cout<<"\n";
        // }
        vector<bool>visited(1e5+5,false);
        queue<pair<int,int>>q;
        int time=0;
        //BFS
        if(graph.empty())return 0;
        q.push({start,0});
        visited[start]=true;
        while(!q.empty()){
            auto [node,height]=q.front();
            q.pop();
            // visited[node]=true;
            time=max(time,height);
            for(int i:graph[node]){
                if(!visited[i]){
                    q.push({i,height+1});
                    visited[i]=true;
                }
            }
        }
        return time;
    }
    void createGraph(TreeNode* root,int parent=-1){
        if(!root)return;
        if(parent!=-1){
            graph[root->val].push_back(parent);
            graph[parent].push_back(root->val);
        }
        createGraph(root->left,root->val);
        createGraph(root->right,root->val);
    }
};
//-1->1