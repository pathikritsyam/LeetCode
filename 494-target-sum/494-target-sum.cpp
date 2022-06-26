class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)sum+=nums[i];
        if(abs(target)>sum)return 0;
        if((target+sum)%2!=0)return 0;
        vector<vector<int>>dp(n+1,vector<int>((target+sum)/2+1,0));
        // for(int i=0;i<n;i++)dp[i][0]=1;
        // for(int i=0;i<=(target+sum)/2;i++)dp[0][i]=1;
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=(target+sum)/2;j++){
                int dont_take=dp[i-1][j];
                int take=0;
                if(nums[i-1]<=j)take=dp[i-1][j-nums[i-1]];
                dp[i][j]=take+dont_take;
            }
        }
        return dp[n][(target+sum)/2];
    }
};