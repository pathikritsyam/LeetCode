class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>res(1<<n);
        for(int i=0;i<(1<<n);i++){
            res[i]=i^(i>>1);
        }
        return res;
    }
};
//0-0
//1-1
//3-11
//2-10
//6-110
//7-111
//5-101
//4-100