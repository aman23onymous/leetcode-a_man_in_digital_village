class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<int> x(m+n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) if(grid[i][j]) x[i]++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) if(grid[j][i]) x[i+m]++;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) grid[i][j] = 2*(x[i]+x[j+m])-m-n;
        }
        return grid;
    }
};