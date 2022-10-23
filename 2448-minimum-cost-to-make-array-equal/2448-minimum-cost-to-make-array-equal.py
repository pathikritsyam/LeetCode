class Solution:
    def minCost(self, A: List[int], C: List[int]) -> int:
        def f(x):
            return sum(abs(a-x)*c for a,c in zip(A,C))
        l,r=min(A),max(A)
        res=f(l)
        while l<r:
            x=(l+r)//2
            f1,f2=f(x),f(x+1)
            res=min(f1,f2)
            if f1<f2: r=x
            else: l=x+1
        return res