class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size()-1;
        vector<int>res;
        // int l=-1,r=n;
        // while(l+1<r){
        //     int m=l+(r-l)/2;
        //     if(nums[m]<=target)l=m;
        //     else r=m;
        // }
        // if(l!=-1)res[0]=l+1;
        // l=-1,r=n;
        // while(l+1<r){
        //     int m=l+(r-l)/2;
        //     if(nums[m]<target)l=m;
        //     else r=m;
        // }
        // if(r!=n)res[1]=r+1;
        if(find(nums.begin(),nums.end(),target)==nums.end())return{-1,-1};
        res.push_back(lower_bound(nums.begin(),nums.end(),target)-nums.begin());
        res.push_back(upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1);
        return res;
    }
};
//[5,7,7,8,8,10]
