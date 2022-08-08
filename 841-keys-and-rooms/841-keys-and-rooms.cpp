class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        unordered_map<int,vector<int>>graph;
        for(int i=0;i<n;i++){
            graph[i]=rooms[i];
        }
        vector<int>vis(n,0);
        queue<int>q;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int i=q.front();
            q.pop();
            for(int it:graph[i]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        for(int i:vis){
            if(i==0)return false;
        }
        return true;
    }
};
//