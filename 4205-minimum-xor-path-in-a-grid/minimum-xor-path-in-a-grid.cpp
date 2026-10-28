class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(1024,0)));
        dp[0][0][grid[0][0]]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i+1<n)for(int k=0;k<1024;k++) if(dp[i][j][k]) dp[i+1][j][k^grid[i+1][j]]=1;
                if(j+1<m)for(int k=0;k<1024;k++) if(dp[i][j][k]) dp[i][j+1][k^grid[i][1+j]]=1;
            }
        }
        for(int k=0;k<1024;k++)if(dp[n-1][m-1][k]) return k;
        return 0;
    }
};