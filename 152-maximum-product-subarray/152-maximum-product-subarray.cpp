class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(),res=-1e9,l=0,r=0;
        for(int i=0;i<n;i++){
            l=(l==0?1:l)*nums[i];
            r=(r==0?1:r)*nums[n-i-1];
            res=max({res,r,l});
        }
        return res;
    }
};