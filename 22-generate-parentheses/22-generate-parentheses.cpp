class Solution {
public:
    vector<string>res;
    void f(string s,int open,int close){
        if(open==0 && close==0){
            res.push_back(s);
            return;
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
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        f("",n,n);
        return res;
    }
};
// 3
//(())