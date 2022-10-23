class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        m,res=int(statistics.median(nums)),0
        for i in nums:
            res+=abs(m-i)
        return res