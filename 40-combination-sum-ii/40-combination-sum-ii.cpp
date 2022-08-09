class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        backtrack(0,target,candidates,temp);
        return ans;
        
    }
    void backtrack(int ind,int target,vector<int>&candidates,vector<int>&temp){
        int n=candidates.size();
        if(target==0){
            ans.push_back(temp);
        }
        for(int i=ind;i<n;i++){
            if(i>ind&&candidates[i]==candidates[i-1])continue;
            if(candidates[i]>target)break;
            temp.push_back(candidates[i]);
            backtrack(i+1,target-candidates[i],candidates,temp);
            temp.pop_back();
        }
    }
};