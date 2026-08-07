class Solution {
public:
    int iia(int i, int j, vector<vector<int>>& mat,
            vector<vector<int>>& dir, vector<vector<int>>& vis) {

        if(vis[i][j]) return vis[i][j];

        vis[i][j] = 1;

        int n = mat.size();
        int m = mat[0].size();

        for(auto x : dir) {
            int nx = i + x[0];
            int ny = j + x[1];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m ||
               mat[nx][ny] >= mat[i][j])
                continue;

            vis[i][j] = max(vis[i][j],
                            1 + iia(nx, ny, mat, dir, vis));
        }

        return vis[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dir = {
            {0,1}, {-1,0}, {1,0}, {0,-1}
        };

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans, iia(i, j, matrix, dir, vis));
            }
        }

        return ans;
    }
};