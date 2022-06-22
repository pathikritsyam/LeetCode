class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<bool>mst(n);
        int cost=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        int i=0;
        while(i<n){
            auto [weight,currnode]=pq.top();
            pq.pop();
            if(mst[currnode])continue;
            cost+=weight;
            mst[currnode]=true;
            i++;
            for(int nextnode=0;nextnode<n;nextnode++){
                if(!mst[nextnode]){
                int nextweight=abs(points[currnode][0]-points[nextnode][0])+abs(points[currnode][1]-points[nextnode][1]);
                pq.push({nextweight,nextnode});
                }
            }
        }
        return cost;
    }
};