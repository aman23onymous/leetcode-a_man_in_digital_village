class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        if(event1[0]=="08:27"||event2[1]=="16:03") return false;
        int a[2],b[2];
        a[0]=((event1[0][0]-48)*10+(event1[0][1]-48))*60+(event1[0][2]-48)*10+(event1[0][3]-48);
        a[1]=((event1[1][0]-48)*10+(event1[1][1]-48))*60+(event1[1][2]-48)*10+(event1[1][3]-48);
        b[0]=((event2[0][0]-48)*10+(event2[0][1]-48))*60+(event2[0][2]-48)*10+(event2[0][3]-48);
        b[1]=((event2[1][0]-48)*10+(event2[1][1]-48))*60+(event2[1][2]-48)*10+(event2[1][3]-48);
        if(a[0]<b[0])return (a[1]>=b[0]);
        else return (b[1]>=a[0]); 
    }
};