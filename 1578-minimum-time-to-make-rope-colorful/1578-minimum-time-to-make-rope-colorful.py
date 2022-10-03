class Solution:
    def minCost(self, C: str, T: List[int]) -> int:
        dp=[0]*len(C)
        for i in range(1,len(C)):
            dp[i]=dp[i-1]
            if C[i]==C[i-1]:
                if T[i-1]<T[i]:
                    dp[i]+=min(T[i-1],T[i])
                else:
                    dp[i]+=min(T[i-1],T[i])
                    T[i],T[i-1]=T[i-1],T[i]
        return dp[-1]