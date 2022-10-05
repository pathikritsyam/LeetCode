class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        s,t='$'+s,'$'+t
        m,n=len(s),len(t)
        dp=[[0]*n for _ in range(m)]
        for j in range(n):dp[0][j]=1
        #dp[i][j]=1 if s[:i] is a subset of t[:j]
        for i in range(m):
            for j in range(1,n):
                if s[i]==t[j]:
                    dp[i][j]=dp[i-1][j-1]
                else:
                    dp[i][j]=dp[i][j-1]
        return dp[-1][-1]
                    