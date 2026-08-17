class Solution {
public:
    int dp[501][502];
    int ret(vector<int>& su,int i,int j){
        if(i>=j) return 0;
        if(1+dp[i][j]) return dp[i][j];
        int mx=0;
        for(int k=i;k<j;k++){
            int n=0;if(i) n=su[i-1];
            if(su[j]-su[k]>su[k]-n) {
                mx= max(mx,su[k]-n+ret(su,i,k));
            }
            else if(su[j]-su[k]<su[k]-n)mx= max(mx,su[j]-su[k]+ret(su,1+k,j));
            else{
                mx= max(mx,su[k]-n+ret(su,i,k));
                mx= max(mx,su[j]-su[k]+ret(su,1+k,j));
            }
        }
        return dp[i][j]=mx;
    }
    int stoneGameV(vector<int>& stv) {
        int n=stv.size();
        memset(dp,-1,sizeof(dp));
        vector<int> su(n,stv[0]);
        for(int i=1;i<n;i++){
            su[i]=(su[i-1]+stv[i]);
        }
        return ret(su,0,n-1);
    }
};