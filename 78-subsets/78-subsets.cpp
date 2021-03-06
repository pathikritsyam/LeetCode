// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<int>ds;
//         vector<vector<int>>ans;
//         f(0,ds,nums,ans);
//         return ans;
//     }
//     void f(int i,vector<int>&ds,vector<int>&nums,vector<vector<int>>&ans){
//         if(i==nums.size()){
//             ans.push_back(ds);
//             return;
//         }
//         //Taking the index
//         ds.push_back(nums[i]);
//         f(i+1,ds,nums,ans);
//         //Not taking the index
//         ds.pop_back();
//         f(i+1,ds,nums,ans);
//     }
// };
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<(1<<n);i++){
            vector<int>sub;
            for(int j=0;j<n;j++){
                if(i&(1<<j))sub.push_back(nums[j]);
            }
            ans.push_back(sub);
        }
        return ans;
    }
};