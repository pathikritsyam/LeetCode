class Solution {
public:
    string smallestNumber(string pattern) {
        string res="",stack;
        for(int i=0;i<=pattern.size();i++){
            stack.push_back(i+'1');
            if(i==pattern.size()||pattern[i]=='I'){
                while(!stack.empty()){
                    res.push_back(stack.back());
                    stack.pop_back();
                }
            }
        }
        return res;
    }
};
//6
//12354