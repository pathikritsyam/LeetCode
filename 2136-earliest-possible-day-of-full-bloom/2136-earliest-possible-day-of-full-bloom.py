class Solution:
    def earliestFullBloom(self, P: List[int], G: List[int]) -> int:
        res=0
        for g,p in sorted(zip(G,P)):
            res=max(res,g)+p
        return res