class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>res={-1,-1};
        int l=-1,r=n;
        while(l+1<r){
            int m=(l+r)/2;
            if(nums[m]<=target)l=m;
            else r=m;
        }
        if(l>-1&&nums[l]==target)res[1]=l;
        l=-1,r=n;
        while(l+1<r){
            int m=(l+r)/2;
            if(nums[m]<target)l=m;
            else r=m;
        }
        if(r<n&&nums[r]==target)res[0]=r;
        return res;
    }
};
//[5,7,7,8,8,10]
