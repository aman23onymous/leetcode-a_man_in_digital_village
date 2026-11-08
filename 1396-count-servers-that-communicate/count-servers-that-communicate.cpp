class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),x=0,y=0;
        map<int,int> sa,sb;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    sa[i]++;
                    sb[j]++;
                    y++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] and sa[i]==1 and sb[j]==1)x++;
            }
        }
        return y-x;
    }
};