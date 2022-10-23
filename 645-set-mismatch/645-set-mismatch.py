class Solution:
    def findErrorNums(self, A: List[int]) -> List[int]:
        m=collections.Counter(A)
        res=[]
        for i in range(1,len(A)+1):
            if m[i]==0:
                res.append(i)
                break
        for i,j in m.items():
            if j==2:
                res.append(i)
                break
        return reversed(res)