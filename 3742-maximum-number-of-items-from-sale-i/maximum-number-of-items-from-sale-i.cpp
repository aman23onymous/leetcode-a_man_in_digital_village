class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> bonus(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0)
                    bonus[i]++;
            }
        }

        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {
            int p = items[i][1];
            int b = bonus[i];

            vector<int> ndp = dp;

            for (int r = 0; r < p; r++) {
                int best = -1e9;

                for (int k = 0, w = r; w <= budget; k++, w += p) {

                    if (k > 0) {
                        best = max(best, dp[w - p] - (k - 1));
                    }

                    if (best > -1e9) {
                        ndp[w] = max(ndp[w], b + k + best);
                    }
                }
            }

            dp.swap(ndp);
        }

        return *max_element(dp.begin(), dp.end());
    }
};