const int N=1e9+7;
class Solution {
public:
    int countVowelPermutation(int n) {
        vector<long long>dp_a(n),dp_e(n),dp_i(n),dp_o(n),dp_u(n);
        dp_a[0]=dp_e[0]=dp_i[0]=dp_o[0]=dp_u[0]=1;
        for(int i=1;i<n;i++){
            dp_a[i]=(dp_e[i-1]+dp_i[i-1]+dp_u[i-1])%N;
            dp_e[i]=(dp_a[i-1]+dp_i[i-1])%N;
            dp_i[i]=(dp_e[i-1]+dp_o[i-1])%N;
            dp_o[i]=dp_i[i-1]%N;
            dp_u[i]=(dp_i[i-1]+dp_o[i-1])%N;
        }
        long long res=0ll;
        res+=(dp_a.back()+dp_e.back()+dp_i.back()+dp_o.back()+dp_u.back())%N;
        return res;
    }
};
//a->e
//e->a,i
//i->a,e,o,u
//o->i,u
//u->a
//-----
//a:e,i,u
//e:a,i
//i:e,o
//o:i
//u:i,o
//--
//n=2
//3+2+2+1+2=10
