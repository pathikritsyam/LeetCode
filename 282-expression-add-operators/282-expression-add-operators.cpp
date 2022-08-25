class Solution {
public:
    string num;
    int target;
    vector<string>res;
    vector<string> addOperators(string num, int target) {
        this->num=num;
        this->target=target;
        backtrack(0,"",0,0);
        return res;
    }
    void backtrack(int i,const string &path,long long resSoFar,long long prevNum){
        if(i==num.length()){
            if(resSoFar==target)res.push_back(path);
            return;
        }
        string s;
        long long n=0;
        for(int j=i;j<num.length();j++){
            if(j>i&&num[i]=='0')break;
            s+=num[j];
            n=n*10+num[j]-'0';
            if(i==0){
                backtrack(j+1,path+s,n,n);
            }
            else{
                backtrack(j+1,path+'+'+s,resSoFar+n,n);
                backtrack(j+1,path+'-'+s,resSoFar-n,-n);
                backtrack(j+1,path+'*'+s,resSoFar-prevNum+n*prevNum,prevNum*n);
            }
        }
    }
};