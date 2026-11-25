class Solution {
public:
    int par[100];
    void init(){
        for(int i=0;i<100;i++) par[i]=i;
    }
    int fin(int u){
        return par[u]=(par[u]==u?u:fin(par[u]));
    }
    int uni(int u,int v){
        u=fin(u);
        v=fin(v);
        if(u==v) return 0;
        par[u]=v;
        return 1;
    }
    int krs(vector<vector<int>>& edges,vector<int>&bb,int n){
        init();
        int ans=0;
        set<int> st;
        for(int i=0;i<edges.size();i++){
            if(bb[i] ==2 and uni(edges[i][0],edges[i][1])) ans+=edges[i][2];
        }
        for(int i=0;i<edges.size();i++){
            if(bb[i] and uni(edges[i][0],edges[i][1])) ans+=edges[i][2];
        }
        for(int i=0;i<n;i++){
            st.insert(fin(i));
        }
        if(st.size()>1) return 1e9;
        return ans;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        for(int i=0;i<m;i++){
            edges[i].push_back(i);
        }
        sort(begin(edges),end(edges),[](vector<int>&a,vector<int>&b){
            return a[2]<b[2];
        });
        vector<int>bb(m,1);
        int mn=krs(edges,bb,n);
        // cout<<mn<<" ";
        vector<vector<int>> a(2);
        for(int i=0;i<m;i++){
            bb[i]=0;
            // cout<<krs(edges,bb)<<" ";
            if(mn<krs(edges,bb,n)) {a[0].push_back(edges[i][3]);bb[i]=1; continue;}
            bb[i]=2;
            if(mn==krs(edges,bb,n)) a[1].push_back(edges[i][3]);
            bb[i]=1;
        }
        return a;
    }
};