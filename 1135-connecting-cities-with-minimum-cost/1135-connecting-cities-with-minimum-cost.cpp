class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto i:connections){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        vector<int>key(n+1,1e9);
        vector<int>mst(n+1,false);
        key[1]=0;key[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,1});
        int cost=0;
        while(!pq.empty()){
            auto [currCost,node]=pq.top();
            pq.pop();
            mst[node]=true;
            for(auto i:adj[node]){
                auto [currNode,weight]=i;
                if(mst[currNode]==false && weight<key[currNode]){
                    key[currNode]=weight;
                    pq.push({key[currNode],currNode});
                }
            }
        }
        for(int i:key){
            if(i==1e9)return -1;
            else cost+=i;
        }
        return cost;
    }
};