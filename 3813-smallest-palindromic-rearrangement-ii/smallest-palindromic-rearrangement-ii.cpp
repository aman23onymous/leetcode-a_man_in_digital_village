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
        int n=s.size();initLogFact(n/2);

        map<char,int>mp;
        for(int i=0;i<n/2;i++) mp[s[i]]++;
        string str="";
        int sz=0;
        if(arrangements(mp)<k) return "";
        while(sz<(n)/2){
            int b=0;
            vector<int> as;
            for(auto &[x,y]:mp){
                if(y==0) continue;

                y--;
                int v=arrangements(mp);
                if(k-1<b+v){
                    str.push_back(x);
                    k-=b;
                    break;
                }
                b+=v;
                y++;
            }
            sz++;
        }
        string trs=str;
        reverse(begin(trs),end(trs));
        if(s.size()%2) return str+s.substr(n/2,1)+trs;
        return str+trs;
    }
};