class MyCalendarThree {
public:
    map<int,int>sweep;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        int cur=0,res=0;
        sweep[start]++;
        sweep[end]--;
        for(auto [_,val]:sweep){
            cur+=val;
            res=max(res,cur);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */