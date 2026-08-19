class Solution {
public:
    long long dp[25][401][2],mod=1000000007;
    long long reti(int i, int x, int t, string &s, int mins, int maxs) {
        if(i == s.size())
            return x >= mins && x <= maxs;
        if(1+dp[i][x][t]) return dp[i][x][t];
        int mn = t ? s[i] - '0' : 9;
        long long su = 0;

        for(int j = 0; j <= mn; j++) {
            int nt = t && (j == s[i] - '0');

            su += reti(i+1, x+j, nt, s, mins, maxs);
            su%=mod;
        }

        return dp[i][x][t]=su;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        string num3="";
        while(num1.back()=='0'){
            num3.push_back('9');
            num1.pop_back();
        }
        num3.push_back(num1.back()-1);
        num1.pop_back();
        while(num1.size()){
            num3.push_back(num1.back());
            num1.pop_back();
        }
        reverse(begin(num3),end(num3));
        memset(dp,-1,sizeof(dp));
        long long x=reti(0,0,1,num2,min_sum,max_sum);
        memset(dp,-1,sizeof(dp));
        long long y=reti(0,0,1,num3,min_sum,max_sum);
        return (x-y+mod)%mod;
    }
};