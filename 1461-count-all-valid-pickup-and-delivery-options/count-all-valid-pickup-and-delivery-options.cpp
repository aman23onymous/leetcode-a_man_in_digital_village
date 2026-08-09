class Solution {
public:
    int countOrders(int n) {
        long long mod = 1e9 + 7;
        long long ans = 1;

        for (int x = 2 * n; x >= 2; x -= 2) {
            long long ways = 1LL * x * (x - 1) / 2;
            ans = ans * ways % mod;
        }

        return ans;
    }
};