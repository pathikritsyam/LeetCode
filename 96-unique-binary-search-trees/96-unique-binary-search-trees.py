class Solution:
    def numTrees(self, n: int) -> int:
        #dp[i]-no of unique BST with n length sequence
        #dp[0]=1,dp[1]=1
        #f(i,n)-no of unique BST where number i is the root & sequence range from 1...n
        #dp[n]=f(1...i,n)+f(i+1..n,n)
        #example:dp[0]=dp[1]*dp[0]+dp[0]*dp[1]
        dp=[0 for _ in range(n+1)]
        dp[0],dp[1]=1,1
        for i in range(2,n+1):
            for j in range(1,i+1):
                dp[i]+=dp[j-1]*dp[i-j]
        return dp[n]
        