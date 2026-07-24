class Solution {
public:
    int distinctSubseqII(string s) {
        map<char,int> st;long long dp[2002]={0},mod=1000000007;
        int n=s.size();
        for(int i=1;i<=n;i++){
            if(!st.count(s[i-1])) dp[i]=dp[i-1]*2+1;
            else dp[i]=2*dp[i-1]-dp[st[s[i-1]]-1]+mod*4;
            st[s[i-1]]=i;
            dp[i]%=mod;
        }
        return dp[n];
    }
};