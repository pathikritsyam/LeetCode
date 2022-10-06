from sortedcontainers import SortedDict
class TimeMap:
    def __init__(self):
        self.mp={}
        
    def set(self, key: str, value: str, timestamp: int) -> None:
        if not key in self.mp:
            self.mp[key]=SortedDict()
        self.mp[key][timestamp]=value

    def get(self, key: str, timestamp: int) -> str:
        if not key in self.mp:
            return ""
        it =self.mp[key].bisect(timestamp)
        if it==0:
            return ""
        return self.mp[key].peekitem(it-1)[1]


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)