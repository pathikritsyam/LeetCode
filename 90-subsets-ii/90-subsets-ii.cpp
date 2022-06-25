class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        backtrack(0,ds,nums,ans);
        return ans;
    }
    void backtrack(int i,vector<int>&ds,vector<int>&nums,vector<vector<int>>&ans){
        if(i==nums.size()){
            ans.push_back(ds);
            return;
        }
        //chosing to add the number
        ds.push_back(nums[i]);
        backtrack(i+1,ds,nums,ans);
        ds.pop_back();
        //chosing to not add the number
        while (i+1<nums.size()&&nums[i]==nums[i+1])i++;
        backtrack(i+1,ds,nums,ans);
    }
};