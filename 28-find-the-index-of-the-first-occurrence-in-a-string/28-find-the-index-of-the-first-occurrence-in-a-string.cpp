class Solution {
public:
    int strStr(string A, string B) {
        if(A.find(B)!=string::npos)
            return A.find(B);
        return -1;
    }
};