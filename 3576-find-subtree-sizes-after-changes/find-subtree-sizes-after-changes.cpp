class Solution {
public:
    vector<vector<int>> adj2;
    vector<vector<int>> adj;
    vector<int> annnss;
    void dfs(int u,int p,vector<int>mp,string&s){
        mp[s[u]-'a']=u;
        for(int x:adj[u]){
            if(x==p) continue;
            if(mp[s[x]-'a']+1){
                // cout<<x<<" "<<mp[s[x]]<<"\n";
                adj2[x].push_back(mp[s[x]-'a']);
                adj2[mp[s[x]-'a']].push_back(x);
            }
            else{
                adj2[x].push_back(u);
                adj2[u].push_back(x);
            }
            dfs(x,u,mp,s);
        }
    }
    int dfs2(int u,int p){
        int ans=1;
        for(int x:adj2[u]){
            if(x==p) continue;
            ans+=dfs2(x,u);
        }
        annnss[u]=ans;
        return ans;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=s.size();
        adj2.resize(n);
        adj.resize(n);
        annnss.resize(n,0);
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }
        vector<int>mmp(26,-1);
        dfs(0,-1,mmp,s);
        dfs2(0,-1);
        return annnss;
    }
};