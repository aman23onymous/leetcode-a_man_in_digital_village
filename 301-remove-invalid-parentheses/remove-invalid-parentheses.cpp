class Solution {
public:
    bool valid(string &s) {
        int cnt = 0;

        for(char c : s) {
            if(c == '(')
                cnt++;
            else if(c == ')') {
                cnt--;
                if(cnt < 0)
                    return false;
            }
        }

        return cnt == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> vis;
        queue<string> q;

        q.push(s);
        vis.insert(s);

        bool found = false;

        while(!q.empty() && !found) {
            int sz = q.size();

            while(sz--) {
                string a = q.front();
                q.pop();

                if(valid(a)) {
                    ans.push_back(a);
                    found = true;
                    continue;
                }

                // Don't generate next level once a valid
                // string has been found at this level.
                if(found)
                    continue;

                for(int i = 0; i < a.size(); i++) {
                    if(a[i] != '(' && a[i] != ')')
                        continue;

                    // Avoid removing consecutive identical
                    // parentheses and generating duplicates.
                    if(i > 0 && a[i] == a[i-1])
                        continue;

                    string b = a.substr(0, i) + a.substr(i + 1);

                    if(!vis.count(b)) {
                        vis.insert(b);
                        q.push(b);
                    }
                }
            }
        }

        return ans;
    }

};