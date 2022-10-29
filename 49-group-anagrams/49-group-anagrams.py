from collections import defaultdict
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d=defaultdict(list)
        for word in strs:
            d["".join(sorted(word))].append(word)
        print(d)
        return list(d.values())