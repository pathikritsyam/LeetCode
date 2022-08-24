class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(nums.size(),vector<int>(2*sum+1,0));
        dp[0][sum+nums[0]]=1;
        dp[0][sum-nums[0]]+=1;
        for(int i=1;i<nums.size();i++){
            for(int j=-sum;j<=sum;j++){
                if(dp[i-1][j+sum]>0){
                    dp[i][j+nums[i]+sum]+=dp[i-1][j+sum];
                    dp[i][j-nums[i]+sum]+=dp[i-1][j+sum];
                }
            }
        }
        return abs(target)>sum?0:dp[nums.size()-1][target+sum];
    }
};