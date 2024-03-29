class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        if(n==2)return "11";
        string s="11";
        int c=1;
        for(int i=3;i<=n;i++){
            string t="";
            s+="$";
            for(int j=1;j<s.size();j++){
                if(s[j]==s[j-1])c++;
                else{
                    t+=to_string(c)+s[j-1];
                    c=1;
                }
            }
            s=t;
        }
        return s;
    }
};