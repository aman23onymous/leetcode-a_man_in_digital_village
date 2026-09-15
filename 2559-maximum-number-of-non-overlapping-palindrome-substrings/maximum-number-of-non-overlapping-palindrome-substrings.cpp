class Solution {
public:
    map<int,int> mp;
    int dip(int i,vector<vector<int>>& dp,int k){
        if(i<0) return 0;
        if(mp.count(i)) return mp[i];
        int mx=dip(i-1,dp,k);
        for(int j=i-k+1;j>=0;j--){
            if(dp[j][i]){
                mx=max(mx,1+dip(j-1,dp,k));
            }
        }
        return mp[i]=mx;
    }
    int maxPalindromes(string s, int l) {
        if(l==1) return s.size();
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++) dp[i][i]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<=n-i;j++){
                int k=j+i-1;
                if(i==2 and (s[k]==s[j])) dp[j][k]=1;
                else if(s[k]==s[j]) dp[j][k]=dp[j+1][k-1];
                // if(dp[j][k]) cout<<j<<k<<" ";
            }
        }
        return dip(n-1,dp,l);
    }
};