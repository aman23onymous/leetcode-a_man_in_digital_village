class Solution {
public:
    int dp[100200];
    bool f(int n){
        if(1+dp[n]) return dp[n];
        for(int i=1;i*i<=n;i++){
            if(!f(n-i*i)) return dp[n]=1;
        }
        return dp[n]=0;
    }
    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof(dp));
        return f(n);
    }
};