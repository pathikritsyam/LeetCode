class Solution {
public:
    vector<int>nums;
    bool good(long x){
        if (nums[0]>x)return 0;
        long prev=nums[0];
        for(int i=1;i<nums.size();i++){
            long d=x-prev;
            prev=nums[i]-d;
            if(prev>x)return 0;
        }
        return 1;
    }
    int minimizeArrayValue(vector<int>& nums) {
        this->nums=nums;
        long l=0,r=1e9;
        for(long i=0;i<100;i++){
            long mid=l+(r-l)/2;
            if(good(mid))r=mid;
            else l=mid;
        }
        return r;
    }
};
//3 7 1 6
//x=5
//