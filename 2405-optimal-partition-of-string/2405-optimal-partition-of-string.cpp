class Solution {
public:
    int partitionString(string s) {
        unordered_set<char>h;
        int ans=0;
        for(char c:s){
            if(h.find(c)!=h.end())ans++,h.clear();
            h.insert(c);
        }
        return ans+1;
    }
};