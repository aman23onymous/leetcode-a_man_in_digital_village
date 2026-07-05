class Solution {
public:
    int mod = 1e9 + 7;

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();

        vector<vector<int>> dp1(n, vector<int>(n, -1));
        vector<vector<int>> dp2(n, vector<int>(n, 0));

        dp1[0][0] = 0;
        dp2[0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X') continue;
                if (i == 0 && j == 0) continue;

                int val = 0;
                if (board[i][j] != 'S' && board[i][j] != 'E')
                    val = board[i][j] - '0';

                if (i && dp1[i - 1][j] != -1) {
                    if (dp1[i][j] < dp1[i - 1][j] + val) {
                        dp1[i][j] = dp1[i - 1][j] + val;
                        dp2[i][j] = dp2[i - 1][j];
                    }
                    else if (dp1[i][j] == dp1[i - 1][j] + val) {
                        dp2[i][j] = (dp2[i][j] + dp2[i - 1][j]) % mod;
                    }
                }

                if (j && dp1[i][j - 1] != -1) {
                    if (dp1[i][j] < dp1[i][j - 1] + val) {
                        dp1[i][j] = dp1[i][j - 1] + val;
                        dp2[i][j] = dp2[i][j - 1];
                    }
                    else if (dp1[i][j] == dp1[i][j - 1] + val) {
                        dp2[i][j] = (dp2[i][j] + dp2[i][j - 1]) % mod;
                    }
                }

                if (i && j && dp1[i - 1][j - 1] != -1) {
                    if (dp1[i][j] < dp1[i - 1][j - 1] + val) {
                        dp1[i][j] = dp1[i - 1][j - 1] + val;
                        dp2[i][j] = dp2[i - 1][j - 1];
                    }
                    else if (dp1[i][j] == dp1[i - 1][j - 1] + val) {
                        dp2[i][j] = (dp2[i][j] + dp2[i - 1][j - 1]) % mod;
                    }
                }
            }
        }

        if (dp1[n - 1][n - 1] == -1) return {0, 0};

        return {dp1[n - 1][n - 1], dp2[n - 1][n - 1]};
    }
};