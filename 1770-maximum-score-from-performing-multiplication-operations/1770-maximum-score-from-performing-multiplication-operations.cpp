class Solution {
public:
    int dp[1005][1005];
    int maximumScore(vector<int>& N, vector<int>& M) {
        int n=N.size(),m=M.size();
        memset(dp,0,sizeof dp);
        //dp[i][j]-maximum value till i th operation & used j number of nums from left
        for(int i=m-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                dp[i][j]=max(M[i]*N[j]+dp[i+1][j+1],M[i]*N[n-1-(i-j)]+dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
};