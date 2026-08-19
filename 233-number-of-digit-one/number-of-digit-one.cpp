class Solution {
public:
    int dp[10][2][10];
    int cnt(int i,int t,int z,string s){
        if(i==s.size()) return z;
        if(1+dp[i][t][z]) return dp[i][t][z];
        int mni=9;
        if(t) mni=s[i]-'0';
        int ans=0;
        for(int j=0;j<=mni;j++){
            if(t and j==s[i]-'0') {ans+=(cnt(i+1,t,z+(j==1),s));}
            else {
                ans+=(cnt(i+1,0,z+(j==1),s));
                // if(i==1)cout<<j<<ans<<" ";
            }
        }
        // if(i==0) cout<<ans<<" ";
        return dp[i][t][z]=ans;
    }
    int countDigitOne(int n) {
        memset(dp,-1,sizeof(dp));
        return cnt(0,1,0,to_string(n));
    }
};