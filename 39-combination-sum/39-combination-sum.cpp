class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>combination;
        backtrack(0,target,candidates,combination);
        return ans;
    }
    void backtrack(int i,int target,vector<int>&candidates,vector<int>&combination){
        int n=candidates.size();
        if(i==n){
            if(target==0){
                ans.push_back(combination);
            }
            return;
        }
        if(candidates[i]<=target){
            combination.push_back(candidates[i]);
            backtrack(i,target-candidates[i],candidates,combination);
            combination.pop_back();
        }
        backtrack(i+1,target,candidates,combination);
    }
};