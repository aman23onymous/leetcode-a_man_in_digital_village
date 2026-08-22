class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int vis[n][m];
        memset(vis,0,sizeof(vis));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<int>> dir={{1,1},{0,1},{0,-1},{1,0},{-1,0}};
        // if(m>1)pq.push({grid[0][0]!=1,0,1});
        // if(n>1)pq.push({grid[0][0]!=1,1,0});
        pq.push({0,0,0});
        while(pq.size()){
            auto x=pq.top();pq.pop();
            if(x[1]==n-1 and x[2]==m-1) return x[0];
            if(vis[x[1]][x[2]]) continue;
            vis[x[1]][x[2]]=1;
            for(int i=1;i<=4;i++){
                int dx=x[1]+dir[i][0],dy=x[2]+dir[i][1];
                if(dx>=n or dy>=m or dx<0 or dy<0) continue;
                pq.push({x[0]+(grid[x[1]][x[2]]!=i),dx,dy});
            }
        }
        return 0;
    }
};