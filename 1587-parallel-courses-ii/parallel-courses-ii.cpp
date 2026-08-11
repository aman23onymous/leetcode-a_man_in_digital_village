class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {

        vector<vector<int>> prq(n);

        for(auto x : relations)
            prq[x[1]-1].push_back(x[0]-1);

        queue<int> q;
        vector<int> dis(1 << n, -1);

        q.push(0);
        dis[0] = 0;

        while(!q.empty()) {

            int mask = q.front();
            q.pop();

            if(mask == (1 << n) - 1)
                return dis[mask];

            int av = 0;

            // Find all currently available courses
            for(int i = 0; i < n; i++) {

                if(mask & (1 << i))
                    continue;

                bool ok = true;

                for(int y : prq[i]) {
                    if((mask & (1 << y)) == 0) {
                        ok = false;
                        break;
                    }
                }

                if(ok)
                    av |= (1 << i);
            }

            // Take all if <= k
            if(__builtin_popcount(av) <= k) {

                int nm = mask | av;

                if(dis[nm] == -1) {
                    dis[nm] = dis[mask] + 1;
                    q.push(nm);
                }
            }
            else {

                // Choose exactly k courses
                for(int sub = av; sub; sub = (sub - 1) & av) {

                    if(__builtin_popcount(sub) != k)
                        continue;

                    int nm = mask | sub;

                    if(dis[nm] == -1) {
                        dis[nm] = dis[mask] + 1;
                        q.push(nm);
                    }
                }
            }
        }

        return -1;
    }
};