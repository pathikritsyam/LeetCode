class Solution {
public:
    const int mod=1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>>A(n);
        for(int i=0;i<n;i++)
            A.push_back({efficiency[i],speed[i]});
        sort(A.begin(),A.end(),[](const pair<int,int> &a,const pair<int,int> &b){
            return a.first>b.first?true:false;
        });
        priority_queue<int,vector<int>,greater<int>>pq;
        long long sum=0,res=0;
        for(auto [e,s]:A){
            pq.push(s);
            sum+=s;
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            res=max(res,sum*e);
        }
        return res%mod;
    }
};