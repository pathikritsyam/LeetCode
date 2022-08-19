class Solution {
public:
    int integerBreak(int n) {
        //maximum will be at n/2
        if(n==2)return 1;
        if(n==3)return 2;
        int no_of_3=n/3;
        int rem=n%3;
        if(rem==1)rem=4,no_of_3--;
        else if(rem==0)rem=1;
        return pow(3,no_of_3)*rem;
    }
};