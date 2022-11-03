class Solution {
public:
    int longestPalindrome(vector<string>& W) {
        unordered_map<string,int>mp;
        for(int i=0;i<W.size();i++){
            mp[W[i]]++;
        }
        int res=0,c=0;
        for(auto i:mp){
            string t=string(i.first.rbegin(),i.first.rend());
            if(t==i.first)res+=2*(i.second/2),c+=(i.second%2);
            else if (mp.find(t)!=mp.end()){
                res+=min(i.second,mp[t]);
            }
        }
        return 2*res+(c?2:0);
    }
};