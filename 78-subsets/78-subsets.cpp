class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>ans;
        f(0,ds,nums,ans);
        return ans;
    }
    void f(int i,vector<int>&ds,vector<int>&nums,vector<vector<int>>&ans){
        if(i==nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        f(i+1,ds,nums,ans);
        ds.pop_back();
        f(i+1,ds,nums,ans);
    }
};