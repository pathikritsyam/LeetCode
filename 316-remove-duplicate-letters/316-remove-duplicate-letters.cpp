class Solution {
public:
    string removeDuplicateLetters(string s) {
        int mp[26];
        unordered_map<char,int> in_deque_mp;
        deque<int> q;
        int n = s.length();
        for(int i = 0; i<n; i++) mp[s[i]-'a'] = i;
        for(int i = 0; i<n; i++) { 
            char c = s[i];
            if(in_deque_mp[c]==0) {
                while(!q.empty() && c<q.back() && mp[q.back()-'a']>i) {
                    in_deque_mp[q.back()]=0;
                    q.pop_back();
                }
                in_deque_mp[c] = 1;
                q.push_back(c);
            }
        }
        string ans="";
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop_front();
        }
        return ans;
    }
};
// cbacdcbc
// c