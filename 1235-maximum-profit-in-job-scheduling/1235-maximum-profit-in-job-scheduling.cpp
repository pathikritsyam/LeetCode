class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        map<int,int>dp;
        unordered_map<int,vector<pair<int,int>>>jobs;
        for(int i=0;i<startTime.size();i++){
            dp[startTime[i]]=0;
            jobs[startTime[i]].push_back({endTime[i],profit[i]});
        }
        int res=0;
        for(auto it=rbegin(dp);it!=rend(dp);it++){
            for(auto j:jobs[it->first]){
                auto it=dp.lower_bound(j.first);
                res=max(res,(it==end(dp)?0:it->second)+j.second);
            }
            it->second=res;
        }
        return res;
    }
};
