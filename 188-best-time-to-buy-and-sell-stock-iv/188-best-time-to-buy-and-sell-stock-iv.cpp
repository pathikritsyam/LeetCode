class Solution {
public:
    int maxProfit(int k, vector<int>& P) {
        if(P.empty())return 0;
        int dp[1005][1005]={{0}};
        //dp[i][j]=maximum profit from at most i transactions using P[0....j]
        for(int i=1;i<=k;i++){
            for(int j=1;j<P.size();j++){
                int maxi=0;
                for(int t=1;t<=j;t++){
                    maxi=max(maxi,P[j]-P[t-1]+dp[i-1][t-1]);
                }
                dp[i][j]=max(dp[i][j-1],maxi);
            }
        }
        return dp[k][P.size()-1];
    }
};