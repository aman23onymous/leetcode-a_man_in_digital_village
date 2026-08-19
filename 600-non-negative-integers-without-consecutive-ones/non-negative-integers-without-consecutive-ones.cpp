class Solution {
public:
    int dp[100][2][3];
    int reti(int i,int t,int pr,string s){
        if(i==s.size()) return 1;
        if(1+dp[i][t][pr]) return dp[i][t][pr];
        int mn=1,ans=0;
        if(t) mn=s[i]-'0';
        for(int j=0;j<=mn;j++){
            if(t and j==mn){
                if(pr!=1 or j!=1)ans+=reti(i+1,1,j,s);
            }
            else if(pr!=1 or j!=1) ans+=reti(i+1,0,j,s);
        }
        return dp[i][t][pr]=ans;
    }
    int findIntegers(int n) {
        string s="";
        memset(dp,-1,sizeof(dp));
        while(n){
            s=to_string(n%2)+s;
            n/=2;
        }
        cout<<s;
        return reti(0,1,2,s);
    }
};