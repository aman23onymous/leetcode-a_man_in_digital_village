class Solution {
public:

    const long long LIMIT = 1000001;
    const long double LOG_LIMIT = logl((long double)1000001);

    vector<long double> logFact;

    void initLogFact(int n) {
        logFact.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            logFact[i] = logFact[i - 1] + logl((long double)i);
        }
    }

    long long arrangements(map<char,int> &freq) {

        int total = 0;
        long double lg = 0;

        for (auto &[c, f] : freq) {
            total += f;
            lg -= logFact[f];
        }

        lg += logFact[total];

        // count definitely greater than k
        if (lg > LOG_LIMIT)
            return LIMIT;


        // exact calculation since answer <= 1e6
        long long ans = 1;
        int rem = total;

        for (auto &[c, f] : freq) {
            if (f == 0) continue;

            // choose positions for this character
            for (int i = 1; i <= f; i++) {
                ans = ans * (rem - f + i) / i;
            }

            rem -= f;

            if (ans >= LIMIT)
                return LIMIT;
        }

        return ans;
    }


    string smallestPalindrome(string s, int k) {

        int n = s.size();

        map<char,int> mp;

        // frequency of first half
        for (char c : s)
            mp[c]++;

        for (auto &[c,f] : mp)
            f /= 2;


        initLogFact(n/2);


        if (arrangements(mp) < k)
            return "";


        string left = "";

        for (int pos = 0; pos < n/2; pos++) {

            long long skipped = 0;

            for (auto &[ch, cnt] : mp) {

                if (cnt == 0) continue;

                cnt--;

                long long ways = arrangements(mp);

                if (k <= skipped + ways) {
                    left.push_back(ch);
                    k -= skipped;
                    break;
                }

                skipped += ways;
                cnt++;
            }
        }


        string right = left;
        reverse(right.begin(), right.end());

        if (n & 1)
            return left + string(1, s[n/2]) + right;

        return left + right;
    }
};