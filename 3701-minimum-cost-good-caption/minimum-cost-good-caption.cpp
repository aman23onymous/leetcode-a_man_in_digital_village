class Solution {
public:
    int dp[50001][27][4];
    string build(int i, int prev, int l, string&caption){
    if(l>=3)l=3;
    int n=caption.size();
    if(i==n)return "";
    int best=dp[i][prev][l];
    int ch=26;
    if(prev!=26){
        int cost=abs((caption[i]-'a')-prev);
        int nl=min(l+1,3);
        if(cost+func(i+1,prev,nl,caption,n)==best){
            ch=prev;
        }
    }
    if(l>=3||prev==26){
        for(int j=0;j<26;j++){
            if(j==prev)continue;
            int cost=abs((caption[i]-'a')-j);
            if(cost+func(i+1,j,1,caption,n)==best){
                ch=min(ch,j);
            }
        }
    }
    if(ch==prev)return char('a'+ch)+build(i+1,prev,l+1,caption);
    return char('a'+ch)+build(i+1,ch,1,caption);
}
    int func(int i,int prev,int l,string &caption,int n){
        if(l>=3)l=3;
        if(i==n&&l>=3)return 0;
        if(i==n&&l<3)return INT_MAX/4;
        int ans=INT_MAX/4;
        if(dp[i][prev][l]!=-1)return dp[i][prev][l];
        if(l>=3||prev>=26){
        for(int j=0;j<26;j++){
            if(j==prev)continue;
            int val=caption[i]-'a';
            ans=min(ans,abs(val-j)+func(i+1,j,1,caption,n));   
        }
        }
        if(prev!=26)ans=min(ans,abs(prev-(caption[i]-'a'))+func(i+1,prev,l+1,caption,n));
        return dp[i][prev][l]=ans;
    }
    string minCostGoodCaption(string caption){
        int n=caption.size();
        memset(dp,-1,sizeof(dp));
        int cost=func(0,26,0,caption,n);
        if(cost>=INT_MAX/4)return "";
        return build(0,26,0,caption);
    }
};