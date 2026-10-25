class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0;
        set<pair<int,int>> st;
        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] or st.count({i,j})) continue;
                queue<pair<int,int>> q;
                int bb=1;
                q.push({i,j});
                while(q.size()){
                    auto x=q.front();q.pop();
                    if(st.count(x)) continue;
                    st.insert(x);
                    if(x.first==0 or x.first==n-1 or x.second==0 or x.second==m-1) bb=0;
                    for(auto y:dir){
                        int nx=y[0]+x.first,ny=y[1]+x.second;
                        if(nx<0 or ny<0 or nx>=n or ny>=m or grid[nx][ny]) continue;
                        q.push({nx,ny});
                    }
                }
                ans+=bb;
            }
        }
        return ans;
    }
};