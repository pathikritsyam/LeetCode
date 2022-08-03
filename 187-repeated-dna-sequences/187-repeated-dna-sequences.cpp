class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string>check,res;
        for(int i=0;i+9<s.length();i++){
            string temp=s.substr(i,10);
            if(!check.insert(temp).second)res.insert(temp);
        }
        vector<string>ans;
        ans.assign(res.begin(),res.end());
        return ans;
    }
};