class Solution {
public:
    int fld[13][13],bs,N,dp[4097][13];
    int ret(int b,int j){
        if(bs==b) return 0;
        int mn=1e8;
        if(1+dp[b][j]) return dp[b][j];
        if(b==0){
            for(int i=0;i<N;i++){
                mn=min(mn,ret((1<<i),i));
            }
        }
        else{
            for(int i=0;i<N;i++){
                if(i==j or (1<<i)&b) continue;
                mn=min(mn,fld[j][i]+ret((1<<i)|b,i));
            }
        }
        return dp[b][j]=mn;
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        memset(dp,-1,sizeof(dp));
        int n=graph.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) fld[i][j]=1e8;
        }
        for(int i=0;i<n;i++){
            for(auto x:graph[i]){
                fld[i][x]=1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    fld[j][k]=min(fld[j][i]+fld[i][k],fld[j][k]);
                }
            }
        }
        N=n;
        bs=(1<<n)-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cout<<fld[i][j]<<" ";
            cout<<"\n";
        }
        return ret(0,12);
    }
};