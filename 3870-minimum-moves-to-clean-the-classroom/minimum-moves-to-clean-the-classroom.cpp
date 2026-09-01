class Solution {
public:
    vector<vector<int>> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int minMoves(vector<string>& g, int e) {
        int r = g.size(), c = g[0].size();
        int si = -1, sj = -1, ltc = 0;
        unordered_map<int, int> lid;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (g[i][j] == 'S') si = i, sj = j;
                else if (g[i][j] == 'L') lid[i * c + j] = ltc++;
            }
        }

        if (ltc == 0) return 0;

        int full = (1 << ltc) - 1;
        vector vis(r, vector(c, vector(e + 1, vector<bool>(1 << ltc))));
        queue<tuple<int, int, int, int, int>> q;

        q.push({si, sj, e, 0, 0});
        vis[si][sj][e][0] = true;

        while (!q.empty()) {
            auto [i, j, en, msk, step] = q.front(); q.pop();
            if (msk == full) return step;

            for (auto& dir : d) {
                int ni = i + dir[0], nj = j + dir[1];
                if (ni < 0 || nj < 0 || ni >= r || nj >= c or !en) continue;
                char ch = g[ni][nj];
                if (ch == 'X') continue;
                
                int ne = en - 1;
                if (ne < 0 && ch != 'R') continue;
                if (ch == 'R') ne = e;

                int nmsk = msk;
                if (ch == 'L') nmsk |= (1 << lid[ni * c + nj]);

                if (!vis[ni][nj][ne][nmsk]) {
                    vis[ni][nj][ne][nmsk] = true;
                    q.push({ni, nj, ne, nmsk, step + 1});
                }
            }
        }

        return -1;
    }
};
