class Solution {
public:
    int dp[101][101];
    int meme(string s,int i,int j){
        if(i>j) return 0;
        if(1+dp[i][j]) return dp[i][j];
        int mx=meme(s,i+1,j)+1;
        for(int k=i+1;k<=j;k++){
            if(s[k]==s[i]) mx=min(mx,meme(s,i+1,k-1)+meme(s,k,j));
        }
        return dp[i][j]=mx;
    }
    int strangePrinter(string s) {
        memset(dp,-1,sizeof(dp));
        return meme(s,0,s.size()-1);
    }
};