class Solution {
public:
    string intToRoman(int n) {
        vector<string>O={"","I","II","III","IV","V","VI","VII","VIII","IX","X"};
        vector<string>T={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        vector<string>H={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        vector<string>TH={"","M","MM","MMM"};
        return TH[n/1000]+H[(n%1000)/100]+T[(n%100)/10]+O[n%10];
    }
};