class Solution {
public:
    int find(vector<int>&par,int x) {return par[x]=(par[x]==x)?x:find(par,par[x]);}
    void uni(vector<int>&par,vector<int>&rank,int a,int b){
        a=find(par,a);
        b=find(par,b);
        if(rank[a]>rank[b]){
            par[b]=a;
            rank[a]++;
        }
        else{
            par[a]=b;
            rank[b]++;
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> compVer;
        unordered_map<int, int> compes;
        vector<int>par(n,1),rank(n,1);
        for(int i=0;i<n;i++) par[i]=i;
        for(auto&x:edges){
            uni(par,rank,x[0],x[1]);
        }
        int ans=0;
        for(int i=0;i<n;i++) {par[i]=find(par,par[i]);compVer[par[i]].insert(i);}
        for(auto&x:edges){
            compes[find(par,x[0])]++;
        }
        for (auto& [comp, nodes] : compVer) {
    if (compes[comp] == nodes.size() * (nodes.size() - 1) / 2) {
        ans++;
    }
}
        return ans;
    }
};