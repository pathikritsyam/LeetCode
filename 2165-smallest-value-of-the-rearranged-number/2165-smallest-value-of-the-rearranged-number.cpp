class Solution {
public:
    long long smallestNumber(long long num) {
        string s=to_string(abs(num));
        int n=s.length();
        sort(s.begin(),s.end());
        if(num<=0){
            reverse(s.begin(),s.end());
            return -1*stoll(s);
        }
        int i=s.find_first_not_of('0');
        swap(s[0],s[i]);
        return stoll(s);
    }
};