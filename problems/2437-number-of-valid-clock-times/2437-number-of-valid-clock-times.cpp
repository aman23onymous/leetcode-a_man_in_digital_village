class Solution {
public:
    int countTime(string time) {
        int a=1,b=1,c=1,d=1;
        if(time[4]=='?') a=10;
        if(time[3]=='?') b=6;
        if(time[0]=='?'){
            if(time[1]=='?') c=24;
            else if(time[1]>51) c=2;
            else c=3;
        }
        if(time[0]!='?'){
            if(time[1]=='?'){
                if(time[0]==50) c=4;
                else c=10;
            }
        }
        return a*b*c;
    }
};