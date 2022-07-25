class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        priority_queue<pair<int,int>>pq;
        for(auto i:pairs)pq.push({i[0],i[1]});
        int res=1;
        auto p=pq.top();
        pq.pop();
        while(!pq.empty()){
            if(p.first>pq.top().second)p=pq.top(),res++;
            pq.pop();
        }
        return res;
    }
};