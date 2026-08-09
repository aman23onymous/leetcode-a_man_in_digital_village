class Solution {
public:
    int dp[101][101];
    int ibn(vector<int>& piles,int i,int m){
        int s=-1e9,su=0,n=piles.size();
        if(i>=n) return 0;
        if(1+dp[i][m]) return dp[i][m];
        for(int j=0;j<2*m and j+i<n;j++){
            su+=piles[i+j];
            s=max(s,su-ibn(piles,i+j+1,max(j+1,m)));
        }
        return dp[i][m]=s;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int s=accumulate(begin(piles),end(piles),0);
        return (ibn(piles,0,1)+s)/2;
        
    }
};