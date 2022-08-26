class Solution {
public:
    const int INF=1e9+5;
    unordered_map<int,vector<pair<int,double>>>adj;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double>prob(n,0);
        priority_queue<pair<double,int>>pq;
        pq.push({1,start});
        prob[start]=1;
        while(!pq.empty()){
            auto [curProb,curNode]=pq.top();
            pq.pop();
            for(auto i:adj[curNode]){
                auto [next,nextProb]=i;
                if(prob[next]<curProb*nextProb){
                    prob[next]=curProb*nextProb;
                    pq.push({prob[next],next});
                }
            }
        }
        return prob[end];
    }
};