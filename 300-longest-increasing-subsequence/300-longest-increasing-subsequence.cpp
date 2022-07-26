class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>res;
        for(int n:nums){
            int i=lower_bound(res.begin(),res.end(),n)-res.begin();
            if(i==res.size())res.push_back(n);
            else if(res[i]>n)res[i]=n;
        }
        return res.size();
    }
};
// 1 7 8 4 5 6 -1 9
// -1 4 5 6 9 