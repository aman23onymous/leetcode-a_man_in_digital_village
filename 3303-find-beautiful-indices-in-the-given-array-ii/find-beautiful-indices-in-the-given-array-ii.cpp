using ll = long long;
class Solution {
public:
    class Rollhash {
    private:
        string s;
        int n;
        vector<ll> rh;
        vector<ll> mul;
        ll mod;

    public:
        Rollhash(string s, int mod) {
            this->s = s;
            this->mod = mod;
            this->n = s.size();
            rh.resize(n, 0);
            mul.resize(n, 1);
            calc();
        }
        void calc() {
            for (int i = 0; i < n; i++) {
                ll ki = 0;
                if (i)
                    ki = rh[i - 1] * 26;
                rh[i] = (ki + s[i] - 'a') % mod;
                if (i)
                    mul[i] = (mul[i - 1] * 26) % mod;
            }
        }
        long long gethash(ll l, ll r) {
            if (l)
                return (rh[r] - (rh[l - 1] * mul[r - l + 1]) % mod + mod) % mod;
            return rh[r];
        }
    };
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.size(), na = a.size(), nb = b.size();
        if (nb > n)
            return {};

        Rollhash rhs(s, 1000000007);
        Rollhash rhb(b, 1000000007);
        Rollhash rha(a, 1000000007);
        Rollhash rhsi(s, 1000000009);
        Rollhash rhbi(b, 1000000009);
        Rollhash rhai(a, 1000000009);

        vector<int> va, vb,ansi;

        for (int i = 0; i + nb <= n; i++) {
            if (rhsi.gethash(i, i + nb - 1) == rhbi.gethash(0, nb - 1) and rhs.gethash(i, i + nb - 1) == rhb.gethash(0, nb - 1))
                va.push_back(i);
        }
        if (a == b)
            return va;
        if (va.size() == 0)
            return va;
        for (int i = 0; i + na <= n; i++) {
            if (rhsi.gethash(i, i + na - 1) == rhai.gethash(0, na - 1) and rhs.gethash(i, i + na - 1) == rha.gethash(0, na - 1)) {
                vb.push_back(i);
            }
        }
        int i,j;
        for( i=0,j=0;i<vb.size() and j<va.size();i++){
            int mni=INT_MAX;
            while(j<va.size() and va[j]<vb[i]) j++;
            if(j) mni=min(mni,vb[i]-va[j-1]);
            if(j<va.size()) mni=min(mni,va[j]-vb[i]);
            if(mni<=k) ansi.push_back(vb[i]);
        }
        while (i < vb.size()) {
    if (abs(va.back() - vb[i]) <= k)
        ansi.push_back(vb[i]);
    i++;
}
        return ansi;

        return vb;
    }
};