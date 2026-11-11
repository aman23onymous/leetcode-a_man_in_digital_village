
class Solution {
public:
    vector<int> stim, etim, dpt, msk, bit;
    int t, n;
    int seg[400010], laz[400010];
    vector<vector<int>> upl;

    void segbld(int id, int lo, int hi) {
        if(lo == hi) {
            seg[id] = msk[lo];
            return;
        }

        int md = (lo + hi) / 2;

        segbld(2*id+1, lo, md);
        segbld(2*id+2, md+1, hi);

        seg[id] = seg[id*2+1] ^ seg[id*2+2];
    }

    void apply(int id, int lo, int hi, int vl) {
        if((hi-lo+1)&1) seg[id] ^= vl;
        laz[id] ^= vl;
    }

    void psh(int id, int lo, int hi) {
        if(laz[id] == 0 || lo == hi) return;

        int md = (lo + hi) / 2;

        apply(id*2+1, lo, md, laz[id]);
        apply(id*2+2, md+1, hi, laz[id]);

        laz[id] = 0;
    }

    void udp(int id, int lo, int hi, int l, int r, int vl) {
        if(lo > r || hi < l) return;

        if(lo >= l && hi <= r) {
            apply(id, lo, hi, vl);
            return;
        }

        psh(id, lo, hi);

        int md = (lo + hi) / 2;

        udp(id*2+1, lo, md, l, r, vl);
        udp(id*2+2, md+1, hi, l, r, vl);

        seg[id] = seg[id*2+1] ^ seg[id*2+2];
    }

    int qry(int id, int lo, int hi, int idx) {
        if(lo == hi) return seg[id];

        psh(id, lo, hi);

        int md = (lo + hi) / 2;

        if(idx <= md)
            return qry(id*2+1, lo, md, idx);

        return qry(id*2+2, md+1, hi, idx);
    }

    void upd(int u, char c) {
        int vl = bit[u] ^ (1 << (c-'a'));

        bit[u] = (1 << (c-'a'));

        udp(0, 0, n-1, stim[u], etim[u], vl);
    }

    void bld(int n) {
        for(int i=1; i<20; i++) {
            for(int j=0; j<n; j++) {
                if(upl[j][i-1] != -1)
                    upl[j][i] = upl[upl[j][i-1]][i-1];
            }
        }
    }

    void eul(vector<vector<int>>& adj, string &s,
             int u, int p, int d, int m) {

        bit[u] = (1 << (s[u]-'a'));
        m ^= bit[u];

        stim[u] = t;
        msk[t] = m;
        t++;

        dpt[u] = d;
        upl[u][0] = p;

        for(int x : adj[u]) {
            if(x == p) continue;
            eul(adj, s, x, u, d+1, m);
        }

        etim[u] = t-1;
    }

    int lca(int u, int v) {
        if(dpt[u] < dpt[v]) swap(u,v);

        int d = dpt[u] - dpt[v];

        for(int i=19; i>=0; i--) {
            if(d & (1<<i))
                u = upl[u][i];
        }

        if(u == v) return u;

        for(int i=19; i>=0; i--) {
            if(upl[u][i] != upl[v][i]) {
                u = upl[u][i];
                v = upl[v][i];
            }
        }

        return upl[u][0];
    }

    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        this->n = n;

        memset(seg, 0, sizeof(seg));
        memset(laz, 0, sizeof(laz));

        stim.resize(n);
        etim.resize(n);
        dpt.resize(n);
        msk.resize(n);
        bit.resize(n);

        upl.assign(n, vector<int>(20, -1));

        vector<vector<int>> adj(n);

        t = 0;

        for(auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        eul(adj, s, 0, -1, 0, 0);

        bld(n);

        segbld(0, 0, n-1);

        vector<bool> ans;

        for(auto q : queries) {
            stringstream ss(q);

            string type;
            int u, v;

            ss >> type >> u;

            if(type == "update") {
                char c;
                ss >> c;

                upd(u, c);
            }
            else {
                ss >> v;

                int w = lca(u, v);

                int a = qry(0, 0, n-1, stim[u]);
                int b = qry(0, 0, n-1, stim[v]);

                int mask = a ^ b ^ bit[w];

                ans.push_back((mask & (mask-1)) == 0);
            }
        }

        return ans;
    }
};