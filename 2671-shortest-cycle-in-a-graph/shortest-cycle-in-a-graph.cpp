class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        int mx = 1e9;
        
        vector<vector<int>> adj(n);
        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for(int s = 0; s < n; s++) {
            vector<int> dist(n, -1), par(n, -1);
            queue<int> q;

            q.push(s);
            dist[s] = 0;

            while(!q.empty()) {
                int x = q.front();
                q.pop();

                for(int y : adj[x]) {
                    if(dist[y] == -1) {
                        dist[y] = dist[x] + 1;
                        par[y] = x;
                        q.push(y);
                    }
                    else if(par[x] != y) {
                        mx = min(mx, dist[x] + dist[y] + 1);
                    }
                }
            }
        }

        return mx == 1e9 ? -1 : mx;
    }
};