class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int res=0;
        int dp[1005][1005];
        //dp[i]-longest subarray length that appears in both the array till i th in A and j th in B
        memset(dp,0,sizeof dp);
        for(int i=1;i<=A.size();i++)
            for(int j=1;j<=B.size();j++)
                if(A[i-1]==B[j-1])
                    dp[i][j]=dp[i-1][j-1]+1,res=max(res,dp[i][j]);
        return res;
    }
};