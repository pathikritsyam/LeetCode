//no_of_sides*p=(no_of_reflections+1)*q
class Solution {
public:
    int mirrorReflection(int p, int q) {
        while(!(p&1)&&!(q&1))p>>=1,q>>=1;
        if(!(p&1)&&q&1)return 2;
        if(p&1&&q&1)return 1;
        return 0;
    }
};