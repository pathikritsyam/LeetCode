class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        long sum=0,ans=0,i=0;
        sort(nums.begin(),nums.end());
        for(int j=0;j<nums.size();j++){
            sum+=nums[j];
            while(sum+k<nums[j]*(j-i+1)){
                sum-=nums[i];
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};