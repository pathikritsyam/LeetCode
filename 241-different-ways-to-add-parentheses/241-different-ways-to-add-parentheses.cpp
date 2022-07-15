class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int>res;
        int n=expression.length();
        for(int i=0;i<n;i++){
            if(expression[i]<'0'){
                vector<int>v1=diffWaysToCompute(expression.substr(0,i));
                vector<int>v2=diffWaysToCompute(expression.substr(i+1));
                for(auto n1:v1)for(auto n2:v2)switch(expression[i]){
                    case '+':res.push_back(n1+n2);break;
                    case '-':res.push_back(n1-n2);break;
                    case '*':res.push_back(n1*n2);
                }
            }
        }
        if(res.empty())res.push_back(stoi(expression));
        return res;
    }
    
};