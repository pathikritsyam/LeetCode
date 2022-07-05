class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length(),m=s.length();
        vector<int>prev(m+1,0),cur(m+1,0);
        string t=s;
        reverse(t.begin(),t.end());
        for(int j=0;j<=m;j++)prev[j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1])cur[j]=1+prev[j-1];
                else cur[j]=max(prev[j],cur[j-1]);
            }
            prev=cur;
        }
        return prev[m];
    }
};