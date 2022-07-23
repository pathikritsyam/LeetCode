from sortedcontainers import SortedList
class Solution(object):
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        s=SortedList()
        # s=[]
        output=[]
        for i in nums[::-1]:
            ans=SortedList.bisect_left(s,i)
            output.append(ans)
            # heapq.heappush(s,i)
            s.add(i)
        return reversed(output)