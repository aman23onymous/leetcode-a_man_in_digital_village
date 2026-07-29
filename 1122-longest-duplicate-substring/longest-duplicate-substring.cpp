class Solution {
public:
    const long long mod1 = 1000000007;
    const long long mod2 = 1000000009;
    const long long base = 26;

    long long p1[30001], p2[30001];

    void init() {
        p1[0] = p2[0] = 1;
        for (int i = 1; i < 30001; i++) {
            p1[i] = (p1[i - 1] * base) % mod1;
            p2[i] = (p2[i - 1] * base) % mod2;
        }
    }

    int ret(string &s, int l) {
        if (l == 0) return 0;

        set<pair<long long,long long>> mp;

        long long h1 = 0, h2 = 0;

        for (int i = 0; i < l; i++) {
            h1 = (h1 * base + (s[i] - 'a')) % mod1;
            h2 = (h2 * base + (s[i] - 'a')) % mod2;
        }

        mp.insert({h1, h2});

        for (int i = l; i < s.size(); i++) {

            h1 = (h1 - 1LL * (s[i-l]-'a') * p1[l-1]) % mod1;
            if (h1 < 0) h1 += mod1;
            h1 = (h1 * base + (s[i]-'a')) % mod1;

            h2 = (h2 - 1LL * (s[i-l]-'a') * p2[l-1]) % mod2;
            if (h2 < 0) h2 += mod2;
            h2 = (h2 * base + (s[i]-'a')) % mod2;

            if (mp.count({h1, h2}))
                return i - l + 1;

            mp.insert({h1, h2});
        }

        return -1;
    }

    string longestDupSubstring(string s) {
        init();

        int lo = 1, hi = s.size();
        int pos = -1, len = 0;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            int p = ret(s, mid);

            if (p != -1) {
                pos = p;
                len = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        if (pos == -1) return "";
        return s.substr(pos, len);
    }
};