class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>hash(n,-1);
        int maxi=-1e9,ind=-1;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(!(nums[i]%nums[j])&&dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                ind=i;
            }
        }
        vector<int>res;
        res.push_back(nums[ind]);
        while(hash[ind]!=ind){
            ind=hash[ind];
            res.push_back(nums[ind]);
        }
        return res;
    }
};
//4 8 10 240
//1 2
// 