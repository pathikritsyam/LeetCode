class Solution {
public:
    string removeDuplicateLetters(string s) {
        int mp[26],dq[26];
        memset(dq,0,sizeof(dq));
        deque<int> q;
        int n = s.length();
        for(int i = 0; i<n; i++) mp[s[i]-'a'] = i;
        for(int i = 0; i<n; i++) { 
            char c = s[i];
            if(dq[c-'a']==0) {
                while(!q.empty() && c<q.back() && mp[q.back()-'a']>i) {
                    dq[q.back()-'a']=0;
                    q.pop_back();
                }
                dq[c-'a'] = 1;
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