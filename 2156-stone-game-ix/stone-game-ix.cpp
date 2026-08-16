class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {};

        for (int x : stones)
            cnt[x % 3]++;

        if (cnt[0] % 2 == 0) {
            // Alice needs both 1 and 2 available.
            return cnt[1] > 0 && cnt[2] > 0;
        }

        // Odd number of zeros.
        // Alice wins only if one side has at least 3 more stones.
        return abs(cnt[1] - cnt[2]) > 2;
    }
};