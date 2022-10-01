class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        x_nheight=sorted([(l,-h,r) for l,r,h in buildings]+[(r,0,None) for _,r,_ in buildings])
        result,max_heap=[[0,0]],[[0,float('inf')]]
        for x,n_height,r in x_nheight:
            while x>=max_heap[0][1]:
                heapq.heappop(max_heap)
            if n_height!=0:
                heapq.heappush(max_heap,[n_height,r])
            cur_max_height=-max_heap[0][0]
            if result[-1][1]!= cur_max_height:
                result.append([x,cur_max_height])
        return result[1:]
            