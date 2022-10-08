class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        ans=-1
        nums.sort()
        max_diff=float('inf')
        for i in range(len(nums)):
            k,n=i+1,len(nums)-1
            while k<n:
                s=nums[i]+nums[k]+nums[n]
                diff=abs(target-s)
                if diff<max_diff:
                    max_diff=diff
                    ans=s
                if s==target:
                    return s
                elif s<target:
                    k+=1
                else:
                    n-=1
        return ans