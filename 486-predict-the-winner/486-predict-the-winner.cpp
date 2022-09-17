class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int dp[n][n];
        //dp[i][j]-score difference b/w player 1 and player 2 in the subarray [i...j]
        // memset(dp,0,sizeof dp);
        for(int i=0;i<n;i++)
            dp[i][i]=nums[i];
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                dp[i][j]=max(nums[i]-dp[i+1][j],nums[j]-dp[i][j-1]);
            }
        }
        return dp[0][n-1]>=0;
    }
};