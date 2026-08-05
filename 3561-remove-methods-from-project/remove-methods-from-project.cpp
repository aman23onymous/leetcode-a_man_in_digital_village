class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& inv) {
        vector<vector<int>> adj(n);
        for(auto x:inv){
            adj[x[0]].push_back(x[1]);
        }
        stack<int> dfs;
        dfs.push(k);
        set<int> sa,sb;
        while(dfs.size()){
            auto x=dfs.top();
            dfs.pop();
            if(sa.count(x)) continue;
            sa.insert(x);
            for(auto y:adj[x]){
                if(sa.count(y)) continue;
                dfs.push(y);
            }
        }
        for(auto x:sa) cout<<x<<" ";
        vector<int> ans;
        for(auto x:inv){
            if(sa.count(x[1]) and !sa.count(x[0])){
                for(int i=0;i<n;i++) ans.push_back(i);
                return ans;
            }
        }
        for(int i=0;i<n;i++){
            if(sa.count(i)) continue;
            ans.push_back(i);
        }
        return ans;
    }
};