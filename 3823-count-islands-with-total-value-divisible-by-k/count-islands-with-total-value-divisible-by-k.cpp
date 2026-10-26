class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size(),ans=0;
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0)),dir={{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if(grid[i][j] and !vis[i][j]){
                long long s=0;
                q.push({i,j});
                while(q.size()){
                    auto x=q.front();q.pop();
                    if(vis[x.first][x.second]) continue;
                    vis[x.first][x.second]=1;
                    s+=1LL*grid[x.first][x.second];
                    for(auto y:dir){
                        int nx=y[0]+x.first,ny=y[1]+x.second;
                        if(nx<0 or ny<0 or nx>=n or ny>=m or vis[nx][ny] or grid[nx][ny]==0) continue;
                        q.push({nx,ny});
                    }
                }
                // cout<<s<<" ";
                if(s%k==0) ans++;
            }
            }
        }
        return ans;
    }
};