class Solution {
public:
    int fin(vector<int>&par,int i){
        return par[i]=(par[i]==i?i:fin(par,par[i]));
    }
    int uni(vector<int>&par,int u,int v){
        u=fin(par,u);
        v=fin(par,v);
        if(u==v) return 0;
        par[u]=v;
        return 1;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> par1(n+1,0),par2(n+1,0);
        for(int i=1;i<=n;i++){
            par1[i]=i;
            par2[i]=i;
        }
        int an1=0,an2=0,a=0,b=0,c=0;
        for(auto x:edges){
            if(x[0]==3){
                an1+=uni(par1,x[1],x[2]);
                an2+=uni(par2,x[1],x[2]);
                a++;
            }
        }
        int an=an1;
        an1=0;an2=0;
        for(auto x:edges){
            if(x[0]==1){
                an1+=uni(par1,x[1],x[2]);
                b++;
            }
            if(x[0]==2){
                an2+=uni(par2,x[1],x[2]);
                c++;
            }
        }
        set<int> vis1,vis2;
        for(int i=1;i<=n;i++){
            vis1.insert(fin(par1,i));
            vis2.insert(fin(par2,i));
        }
        if(vis1.size()==1 and vis2.size()==1)return a-an+b-an1+c-an2;
        return -1;
    }
};