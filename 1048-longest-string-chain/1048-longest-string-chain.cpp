class Solution {
public:
    static bool comp(string &s1,string &s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int res=0;
        unordered_map<string,int>dp;
        for(auto w:words){
            for(int i=0;i<w.size();i++){
                string temp=w.substr(0,i)+w.substr(i+1);
                dp[w]=max(dp[w],dp.find(temp)==dp.end()?1:dp[temp]+1);
            }
            res=max(res,dp[w]);
        }
        return res;
    }
};