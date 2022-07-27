class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size(),maxi=0,res=0;
        vector<int>dp(n,1),count(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]&&dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    count[i]=count[j];
                }
                else if(nums[i]>nums[j]&&dp[i]==dp[j]+1)count[i]+=count[j];
            }
            if(dp[i]>maxi)maxi=dp[i];
        }
        for(int i=0;i<n;i++){
            if(dp[i]==maxi)res+=count[i];
        }
        return res;
    }
};