class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,int>hash;
        vector<vector<int>>res;
        for(int i=0;i<n-2;i++){
            if(i==0||(i>0&&nums[i]!=nums[i-1])){
                int lo=i+1,hi=n-1,sum=0-nums[i];
                while(lo<hi){
                    vector<int>temp;
                    if(nums[lo]+nums[hi]==sum){
                        temp.push_back(nums[i]);
                        temp.push_back(nums[lo]);
                        temp.push_back(nums[hi]);
                        res.push_back(temp);
                        while(lo<hi&&nums[lo]==nums[lo+1])lo++;
                        while(lo<hi&&nums[hi]==nums[hi-1])hi--;
                        lo++;hi--;
                    }
                    else if(nums[lo]+nums[hi]<sum)lo++;
                    else hi--;
                }
            }
        }
        return res;
    }
};
//-1