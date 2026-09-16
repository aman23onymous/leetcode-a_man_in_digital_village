class MyCalendarThree {
public:
    map<int,int>mp;
    MyCalendarThree() {
        
    }
    
    int book(int stt, int ett) {
        mp[stt]++;
        mp[ett]--;
        int b=0,mx=0;
        for(auto x:mp){
            b+=x.second;
            mx=max(mx,b);
        }
        return mx;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */