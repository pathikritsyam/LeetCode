class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(int i=0;i<nums.size();i++)sum+=nums[i];
        if(sum&1)return false;
        int target=sum/2;
        vector<vector<bool>>dp(n,vector<bool>(sum/2+1,false));
        for(int i=0;i<n;i++)dp[i][0]=true;
        if(nums[0]<=target)dp[0][nums[0]];
        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                bool dont_take=dp[i-1][j];
                bool take=false;
                if(nums[i]<=j)take=dp[i-1][j-nums[i]];
                dp[i][j]=take+dont_take;
            }
        }
        return dp[n-1][sum/2];
    }
};