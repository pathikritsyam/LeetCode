class Solution:
    def reverseWords(self, s: str) -> str:
        t=s.split()
        res=""
        for i in t:
            i=i[::-1]
            res+=i+" "
        res=res.strip()
        return res