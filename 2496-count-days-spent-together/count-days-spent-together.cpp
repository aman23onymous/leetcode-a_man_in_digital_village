class Solution {
public:
    int countDaysTogether(string ara, string la, string arb, string lb) {
        vector<int> a={0,0,31,59,90,120,151,181,212,243,273,304,334};
        int sta=stoi(ara.substr(3))+a[stoi(ara.substr(0,2))];
        int lla=stoi(la.substr(3))+a[stoi(la.substr(0,2))];
        int stb=stoi(arb.substr(3))+a[stoi(arb.substr(0,2))];
        int llb=stoi(lb.substr(3))+a[stoi(lb.substr(0,2))];
        if(llb<stb) llb+=365;
        if(lla<sta) lla+=365;
        int mn=max(sta,stb);
        int mx=min(lla,llb);
        return max(mx-mn+1,0);
    }
};