class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        vector<int> first(s2.size(), -1);
        vector<long long> cnt(n1 + 1, 0);

        int j = 0;

        for (int i = 1; i <= n1; i++) {

            // Your matching approach:
            // scan one complete s1 and continue from current j
            for (int x = 0; x < s1.size(); x++) {
                if (s1[x] == s2[j]) {
                    j++;

                    if (j == s2.size()) {
                        j = 0;
                        cnt[i]++;
                    }
                }
            }

            cnt[i] += cnt[i - 1];

            // Same j after processing an s1 block => cycle
            if (first[j] != -1) {
                int st = first[j];

                int cycleLen = i - st;
                long long cycleCnt = cnt[i] - cnt[st];

                long long ans = cnt[st];

                int rem = n1 - st;

                ans += (rem / cycleLen) * cycleCnt;

                int left = rem % cycleLen;

                ans += cnt[st + left] - cnt[st];

                return ans / n2;
            }

            first[j] = i;
        }

        return cnt[n1] / n2;
    }
};