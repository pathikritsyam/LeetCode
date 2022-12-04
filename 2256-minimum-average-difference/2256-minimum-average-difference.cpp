class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size(),mini=INT_MAX,idx;
        long long sfe=0,sff=0;
        for(auto num:nums)sfe+=num;
        for(int i=0;i<n;i++){
            sff+=nums[i];
            sfe-=nums[i];
            int a=round(sff/(i+1));
            int b=i==n-1?0:round(sfe/(n-i-1));
            if(abs(a-b)<mini){
                mini=abs(a-b);
                idx=i;
            }
        }
        return idx;
    }
};