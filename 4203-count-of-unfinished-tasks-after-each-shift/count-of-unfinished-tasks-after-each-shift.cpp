class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();

        vector<long long> pref(n);
        pref[0] = tasks[0];
        for (int i = 1; i < n; i++)
            pref[i] = pref[i - 1] + tasks[i];

        long long done = 0;
        vector<int> ans;

        for (int x : shifts) {
            done += x;

            if (done >= pref[n - 1]) {
                ans.push_back(0);
                done = 0;
                continue;
            }

            int finished = upper_bound(pref.begin(), pref.end(), done) - pref.begin();
            ans.push_back(n - finished);
        }

        return ans;
    }
};