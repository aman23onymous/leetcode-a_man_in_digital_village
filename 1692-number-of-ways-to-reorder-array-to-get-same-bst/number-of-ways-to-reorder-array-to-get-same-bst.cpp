
class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[1005][1005];

    void precompute() {
        for (int i = 0; i < 1005; i++) {
            dp[i][0] = 1;
            dp[i][i] = 1;

            for (int j = 1; j < i; j++) {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
            }
        }
    }

    int bbc(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) return 1;

        vector<int> left, right;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0]) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        long long ways = dp[n-1][left.size()];
        ways = ways * bbc(left) % MOD;
        ways = ways * bbc(right) % MOD;

        return ways;
    }

    int numOfWays(vector<int>& nums) {
        precompute();
        return (bbc(nums) - 1 + MOD) % MOD;
    }
};