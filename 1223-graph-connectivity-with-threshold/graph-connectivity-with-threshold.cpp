class Solution {
public:
    int par[100001];
    int fin(int u){
        return par[u]=((par[u]==u)?u:fin(par[u]));
    }
    void uni(int u,int v){
        par[fin(u)]=fin(v);
    }
    vector<bool> areConnected(int n, int thr, vector<vector<int>>& q) {
        for(int i=0;i<=100000;i++){
            par[i]=i;
        }
        for(int i=thr+1;i<=n;i++){
            for(int j=i;j<=n;j+=i){
                uni(i,j);
            }
        }
        vector<bool> ans;
        for(auto x:q){
            ans.push_back(fin(x[0])==fin(x[1]));
        }
        return ans;
    }
};