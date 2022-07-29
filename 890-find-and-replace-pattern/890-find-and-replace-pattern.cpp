class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>res;
        string p=f(pattern);
        for(string w:words)if(p==f(w))res.push_back(w);
        return res;
    }
    string f(string s){
        unordered_map<char,char>mp;
        char c='a';
        for(auto ch:s)if(mp.find(ch)==mp.end())mp[ch]=c++;
        for(auto &ch:s)ch=mp[ch];
        return s;
    }
};
// ssbc
// s->a
// b->b
// c->c