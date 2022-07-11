class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<int,string>mp={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
        vector<string>res;
        if(digits.size()==0)return res;
        f(digits,0,res,mp,"");
        return res;
    }
    void f(string &s,int index,vector<string>&res,map<int,string>mp,string temp){
        
        if(temp.length()==s.length()){
            res.push_back(temp);
            return;
        }
        for(char j:mp[s[index]-'0']){
            temp+=j;
            f(s,index+1,res,mp,temp);
            temp.pop_back();
        }
    }
};