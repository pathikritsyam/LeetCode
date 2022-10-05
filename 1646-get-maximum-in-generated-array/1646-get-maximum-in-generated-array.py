class Solution:
    def getMaximumGenerated(self, n: int) -> int:
        dp=[0]*(n+3)
        dp[0],dp[1]=0,1
        maxi=-1
        for i in range(n+1):
            if i%2==0:
                dp[i]=dp[i//2]
            else:
                dp[i]=dp[i//2]+dp[i//2+1]
            maxi=max(maxi,dp[i])
        return maxi
            