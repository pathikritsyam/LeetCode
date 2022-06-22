class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sum=target-nums[i];
            if(mp.find(sum)!=mp.end()){
                ans.push_back(mp[sum]);
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]]=i;
        }
        return ans;
    }
};