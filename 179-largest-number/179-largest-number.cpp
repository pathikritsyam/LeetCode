class Solution {
    static bool comp(string &s1,string &s2){
        return s1+s2>s2+s1;
    }
public:
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        vector<string>n_nums(n);
        for(int i=0;i<n;i++){
            n_nums[i]=to_string(nums[i]);
        }
        sort(n_nums.begin(),n_nums.end(),comp);
        string res;
        for(int i=0;i<n;i++){
            res+=n_nums[i];
        }
        while(res[0]=='0' && res.length()>1)
            res.erase(0,1);
        return res;
    }
};
// [3,30,34,5,9]
// 9534330
//303,330