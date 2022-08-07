class Solution {
public:
    int findTheWinner(int n, int k) {
        return f(k,n)+1;
    }
    int f(int k,int n){
        if(n==1)return 0;
        return (f(k,n-1)+k)%n;
    }
};
//.        i
// 1 2 3 4 5
// 3