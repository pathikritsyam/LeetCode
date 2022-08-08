class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        unordered_map<int,vector<int>>adj;
        int n=bombs.size();
        for(int i=0;i<n;i++){
            long long r=(long long)bombs[i][2]*bombs[i][2];
            long long x=bombs[i][0],y=bombs[i][1];
            for(int j=0;j<n;j++){
                if(pow(x-bombs[j][0],2)+pow(y-bombs[j][1],2)<=r){
                    adj[i].push_back(j);
                }
            }
        }
        int maxi=0;
        for(int i=0;i<n&&maxi<n;i++){
            vector<int>visited(n,0);
            maxi=max(maxi,dfs(adj,i,visited));
        }
        return maxi;
    }
    int dfs(unordered_map<int,vector<int>>&adj,int node,vector<int>&visited){
        if(!visited[node]){
            visited[node]=1;
            for(auto i:adj[node]){
                dfs(adj,i,visited);
            }
        }
        return count(visited.begin(),visited.end(),1);
    }
};