class Solution {
public:
    vector<string>res;
    vector<string> f(string s,int open,int close){
        if(open==0 && close==0){
            res.push_back(s);
            return res;
        }
        if(open>0){
            s+='(';
            f(s,open-1,close);
            s.pop_back();
        }
        if(close>0){
            if(open<close){
                s+=')';
                f(s,open,close-1);
                s.pop_back();
            }
        }
        return res;
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        vector<vector<string>>dp(n+1,vector<string>(n+1,"k"));
        return f(s,n,n);
    }
};
// 3
//(())