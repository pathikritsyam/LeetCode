class Solution {
public:
    int calculate(string s) {
        //digits
        //operator
        //parenthesis
        //stack
        stack<int>st;
        int sign=1,cur=0,res=0;
        for(auto i:s){
            if(isdigit(i)){
                cur=cur*10+(i-'0');
            }
            else if(i=='+'||i=='-'){
                res+=(cur*sign);
                cur=0;
                if(i=='+')sign=1;
                else sign=-1;
            }
            else if(i=='('){
                st.push(res);
                st.push(sign);
                res=0;
                sign=1;
            }
            else if(i==')'){
                res+=(cur*sign);
                res*=st.top();st.pop();
                res+=st.top();st.pop();
                cur=0;
            }
        }
        return res+(cur*sign);
    }
};
//"(1+(4+5+2)-3)+(6+8)"
//" 2-1 + 2 "