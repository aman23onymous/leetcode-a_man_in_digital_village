class Solution {
public:
    void dfs(int u,vector<vector<int>>&adj,vector<int>&ans){
        for(int x:adj[u]){
            if(ans[x]==-1){
                ans[x]=ans[u]+1;
                dfs(x,adj,ans);
            }
        }
    }
    vector<int> countVisitedNodes(vector<int>& edg) {
        int n=edg.size();
        vector<int> ind(n,0);
        vector<vector<int>> adj(n),jda(n);
        for(int i=0;i<n;i++){
            ind[edg[i]]+=1;
            adj[i].push_back(edg[i]);
            jda[edg[i]].push_back(i);
        }
        queue<int> q;
        for(int i=0;i<n;i++) if(ind[i]==0) q.push(i);
        while(q.size()){
            int x=q.front();
            q.pop();
            for(int y:adj[x]){
                ind[y]--;
                if(ind[y]==0) q.push(y);
            }
        }
        vector<int> ans(n,-1);
        set<int> vis;
        for(int i=0;i<n;i++){
            if(ind[i] and ans[i]==-1){
                int x=edg[i],c=1;
                while(x!=i) {x=edg[x];c++;}
                ans[x]=c;
                x=edg[x];
                while(x!=i) {ans[x]=c;x=edg[x];}
                dfs(i,jda,ans);
            }
        }
        for(int i=0;i<n;i++){
            if(ans[i]+1){
                dfs(i,jda,ans);
            }
        }
        return ans;
    }
};