class Solution {
public:
    vector<vector<unordered_set<int>>> dp;

    unordered_set<int> solve(vector<int>& nums, vector<char>& op, int l, int r) {
        if (!dp[l][r].empty()) return dp[l][r];

        if (l == r) {
            dp[l][r].insert(nums[l]);
            return dp[l][r];
        }

        for (int i = l; i < r; i++) {
            auto left = solve(nums, op, l, i);
            auto right = solve(nums, op, i + 1, r);

            for (int a : left) {
                for (int b : right) {
                    int val;
                    if (op[i] == '+')
                        val = a + b;
                    else
                        val = a * b;

                    if (val <= 1000)
                        dp[l][r].insert(val);
                }
            }
        }

        return dp[l][r];
    }

    int scoreOfStudents(string s, vector<int>& answers) {
        vector<int> nums;
        vector<char> op;

        for (int i = 0; i < s.size(); i++) {
            if (i % 2)
                op.push_back(s[i]);
            else
                nums.push_back(s[i] - '0');
        }

        // correct answer
        int sum = 0;
        int cur = 1;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*')
                continue;
            if (s[i] == '+') {
                sum += cur;
                cur = 1;
            } else {
                cur *= (s[i] - '0');
            }
        }
        sum += cur;

        int n = nums.size();
        dp.assign(n, vector<unordered_set<int>>(n));

        auto possible = solve(nums, op, 0, n - 1);

        int ans = 0;

        for (int x : answers) {
            if (x == sum)
                ans += 5;
            else if (possible.count(x))
                ans += 2;
        }

        return ans;
    }
};