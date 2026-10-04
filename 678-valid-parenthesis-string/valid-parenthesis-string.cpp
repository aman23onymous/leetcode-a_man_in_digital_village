class Solution {
public:
    int dp[101][101];
    int dpi(string&s,int i,int l){
        if(i==s.size()) return l==0;
        if(l<0) return 0;
        if(1+dp[i][l]) return dp[i][l];
        int ms=0;
        if(s[i]=='(') ms+=dpi(s,i+1,l+1);
        else if(s[i]==')') ms+=dpi(s,i+1,l-1);
        else{
            ms+=dpi(s,i+1,l+1);
            if(ms) return dp[i][l]=ms;
            ms+=dpi(s,i+1,l);
            if(ms) return dp[i][l]=ms;
            ms+=dpi(s,i+1,l-1);
        }
        return dp[i][l]=ms;
    }
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        return dpi(s,0,0);
    }
};