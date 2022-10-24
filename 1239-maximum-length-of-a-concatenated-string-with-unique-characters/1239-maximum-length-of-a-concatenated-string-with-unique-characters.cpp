class Solution {
public:
    int maxLength(vector<string>& A) {
        vector<bitset<26>>dp(1,bitset<26>());
        int res=0;
        for(auto &a:A){
            bitset<26>w;
            for(auto &c:a)
                w.set(c-'a');
            int c=w.count();
            if(c<a.size())continue;
            for(int i=0;i<dp.size();i++){
                bitset b=dp[i];
                if((w&b).any())continue;
                dp.push_back(w|b);
                res=max(res,(int)b.count()+c);
            }
        }
        return res;
    }
};