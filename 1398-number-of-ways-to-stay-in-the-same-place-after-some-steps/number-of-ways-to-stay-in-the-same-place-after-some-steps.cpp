class Solution {
public:
    long long dp[501][10001],mod=1000000007;
    long long reti(int st,int pos,int n){
        if(st==0) return pos==0;
        if(1+dp[st][pos]) return dp[st][pos];
        long long ans=reti(st-1,pos,n);
        if(pos) ans+=reti(st-1,pos-1,n);
        if(pos<n-1) ans+=reti(st-1,pos+1,n);
        return dp[st][pos]=ans%mod;
    }
    int numWays(int steps, int arrLen) {
        memset(dp,-1,sizeof(dp));
        return reti(steps,0,arrLen);
    }
};