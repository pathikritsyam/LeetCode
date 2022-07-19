class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>dp(numRows);
        //dp[0][0]=1;
        for(int i=0;i<numRows;i++){
            dp[i]=vector<int>(i+1);
            for(int j=0;j<=i;j++){
                if(j==0||j==i)dp[i][j]=1;
                else dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
        }
        return dp;
    }
};