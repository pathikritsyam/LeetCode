class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>morse={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_map<string,int>transform;
        for(string word:words){
            string st="";
            for(char c:word){
                st+=morse[c-'a'];
            }
            transform[st]++;
        }
        int res=0;
        for(auto i:transform){
            res++;
        }
        return res;
    }
};