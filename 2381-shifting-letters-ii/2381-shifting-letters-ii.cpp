class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int>dp(s.size()+1,0);
        for(auto &shift:shifts){
            dp[shift[0]]+=shift[2]==1?1:-1;
            dp[shift[1]+1]+=shift[2]==1?-1:1;
        }
        for(int i=1;i<s.size();i++){
            dp[i]+=dp[i-1];
        }
        for(int i=0;i<s.size();i++){
            int increaseBy=(s[i]-'a'+dp[i])%26;
			increaseBy=(increaseBy+26)%26;
			s[i]='a'+increaseBy;
        }
        return s;
    }
};
//a