class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            ans.push_back(__builtin_popcount(i));
        }
        return ans;
    }
};
// 0 1 10 11 100 101 110 111 1000 1001 1010 1011 1100 1101 1110 1111 10000 10001 10010 10011 10100 10101 10110 10111 11000 11001 11010 11011 11111
// 0 1 1 2 1 2 2 3 1 2 2 3 2 3 3 4 1 2 2 3 2 3 3 4 2 3 3 4 5