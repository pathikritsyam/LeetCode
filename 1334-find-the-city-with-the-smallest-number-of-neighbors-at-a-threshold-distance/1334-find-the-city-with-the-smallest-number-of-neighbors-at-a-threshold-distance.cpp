class Solution {
public:
    int djikstra(int source,vector<vector<pair<int,int>>>&adj,int n,int dt){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,source});
        vector<int>dist(n,1e9);
        dist[source]=0;
        while(!pq.empty()){
            auto [curdist,node]=pq.top();
            pq.pop();
            for(auto it:adj[node]){
                int next=it.first;
                int d=it.second;
                if(dist[next]>curdist+d){
                    dist[next]=curdist+d;
                    pq.push({dist[next],next});
                }
            }
        }
        int tot=0;
        for(int i=0;i<n;i++){
            tot+=dist[i]<=dt;
        }
        return tot;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        int res=-1,found=1e9;
        for(int i=0;i<n;i++){
            int f=djikstra(i,adj,n,distanceThreshold);
            if(f<=found)found=f,res=i;
        }
        return res;
    }
};