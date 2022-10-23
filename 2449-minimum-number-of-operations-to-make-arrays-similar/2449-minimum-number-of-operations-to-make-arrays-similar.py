class Solution:
    def makeSimilar(self, A: List[int], T: List[int]) -> int:
        A.sort(key=lambda x:(x%2,x))
        T.sort(key=lambda x:(x%2,x))
        return sum(abs(a-t) for a,t in zip(A,T))//4