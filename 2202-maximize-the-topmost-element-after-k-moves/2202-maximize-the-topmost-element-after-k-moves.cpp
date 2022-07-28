class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1&&k&1)return -1;
        else if(k<2)return nums[k];
        else if(k>=n)return *max_element(nums.begin(),nums.end()-(k==n));
        return max(nums[k],*max_element(nums.begin(),nums.begin()+k-1));
    }
};