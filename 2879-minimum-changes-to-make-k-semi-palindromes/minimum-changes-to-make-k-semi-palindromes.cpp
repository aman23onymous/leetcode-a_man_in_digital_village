class Solution {
public:
    int dp[201][201];
    int cost[201][201];

    int cc(string s) {
        int mx = 1e9;

        for (int l = 1; l <= s.size() / 2; l++) {
            if (s.size() % l) continue;

            int tt = 0;

            for (int i = 0; i < l; i++) {
                for (int j = 0, x = i, y = i + l; 
                     y < s.size(); 
                     x += l, y += l) {
                    // Compare symmetric elements in this group
                }

                string t = "";
                for (int j = i; j < s.size(); j += l)
                    t.push_back(s[j]);

                for (int j = 0, k = t.size() - 1; j < k; j++, k--)
                    tt += (t[j] != t[k]);
            }

            mx = min(mx, tt);
        }

        return mx;
    }

    int reti(string &s, int k, int i, int j) {
        if (i == s.size() && j == k) return 0;
        if (i >= s.size() || j >= k) return 1e9;

        if (dp[i][j] != -1) return dp[i][j];

        int mx = 1e9;

        for (int l = i + 2; l <= s.size(); l++) {
            mx = min(mx, cost[i][l - 1] + reti(s, k, l, j + 1));
        }

        return dp[i][j] = mx;
    }

    int minimumChanges(string s, int k) {
        memset(dp, -1, sizeof(dp));

        int n = s.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                cost[i][j] = cc(s.substr(i, j - i + 1));
            }
        }

        return reti(s, k, 0, 0);
    }
};