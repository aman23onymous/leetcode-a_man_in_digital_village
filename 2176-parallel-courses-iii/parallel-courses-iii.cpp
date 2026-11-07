class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& rel, vector<int>& tim) {
        vector<int> a(n,0),ind(n,0);
        vector<vector<int>> adj(n);
        for(auto x:rel){
            adj[x[0]-1].push_back(x[1]-1);
            ind[x[1]-1]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++) if(ind[i]==0) {q.push(i);a[i]=max(a[i],tim[i]);}
        while(q.size()){
            int x=q.front();q.pop();
            for(int y:adj[x]){
                a[y]=max(a[y],a[x]+tim[y]);
                ind[y]--;
                if(ind[y]==0) q.push(y);
            }
        }
        return *max_element(begin(a),end(a));
    }
};