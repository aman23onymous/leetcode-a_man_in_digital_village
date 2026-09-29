class Solution {
public:

    int dpp[101][101][1001];

    int dpi(int i, int j, int b, vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        if(i >= n || j >= m)
            return 0;

        // Process current cell
        if(grid[i][j] == '(')
            b++;
        else
            b--;

        // Invalid prefix
        if(b < 0)
            return 0;

        // Check memo
        if(dpp[i][j][b] != -1)
            return dpp[i][j][b];

        // Last cell
        if(i == n-1 && j == m-1)
            return dpp[i][j][b] = (b == 0);

        return dpp[i][j][b] =
            (dpi(i, j+1, b, grid) |
             dpi(i+1, j, b, grid));
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        memset(dpp, -1, sizeof(dpp));

        return dpi(0, 0, 0, grid);
    }
};