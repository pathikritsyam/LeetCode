class MyCalendar {
public:
    vector<pair<int, int>> reg;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto [s,e]:reg){
            if(max(s,start)<min(e,end))return false;
        }
        reg.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
//[10,20],[8,9]