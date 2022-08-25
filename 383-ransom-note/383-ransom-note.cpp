class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>h(26,0);
        for(char c:ransomNote)h[c-'a']++;
        for(char c:magazine)if(h[c-'a']>0)h[c-'a']--;
        for(int i:h)if(i!=0)return false;
        return true;
    }
};