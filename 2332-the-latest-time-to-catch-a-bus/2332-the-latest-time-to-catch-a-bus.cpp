class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(),buses.end());
        sort(passengers.begin(),passengers.end());
        int k=0;
        set<int>s;
        // for(i=0;i<passengers.size()||k<buses.size();i++){
        //     if(k>=buses.size())break;
        //     int c=capacity;
        //     while(buses[k]>=passengers[i]&&capacity>0){
        //         i++;
        //         capacity--;
        //     }i--;k++;capacity=c;
        // }
        // while(i>0){
        //     if(passengers[i]-1!=passengers[i-1])return passengers[i-1];
        // }
        // return passengers[i-1];
        for(int i=0;i<buses.size();i++){
            int c=capacity,l;
            while(c>0&&k<passengers.size()&&passengers[k]<=buses[i]){
                l=passengers[k];
                s.insert(passengers[k++]),c--;
            }
            if(i==buses.size()-1&&c>0&&l<buses[i])return buses.back();
        }
        if(s.empty())return buses.back();
        auto it=s.rbegin();
        int ans=*it;
        while(s.find(ans)!=s.end())ans--;
        return ans;
    }
};