class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<int> a(n,1e9),b(n,1e9);
        vector<vector<pair<int,int>>> adj(n);
        for(auto x:edges){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        while(pq.size()){
            auto x=pq.top();
            pq.pop();
            if(x.first>=a[x.second]) continue;
            a[x.second]=x.first;
            for(auto y:adj[x.second]){
                if(y.second+x.first<a[y.first]) pq.push({y.second+x.first,y.first});    
            }
        }
        pq.push({0,n-1});
        while(pq.size()){
            auto x=pq.top();
            pq.pop();
            if(x.first>=b[x.second]) continue;
            b[x.second]=x.first;
            for(auto y:adj[x.second]){
                if(y.second+x.first<b[y.first]) pq.push({y.second+x.first,y.first});    
            }
        }
        vector<bool> ans;
        for(auto x:edges){
            if(a[x[0]] + x[2] + b[x[1]] == a[n-1] ||
               a[x[1]] + x[2] + b[x[0]] == a[n-1]) ans.push_back(1);
            else ans.push_back(0);
        }
        return ans;
    }
};