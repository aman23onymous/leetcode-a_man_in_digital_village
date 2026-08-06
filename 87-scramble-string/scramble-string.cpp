class Solution {
public:
    int dp[31][31][31][31];
    bool reti(string s1, string s2,int i,int j,int k,int l){
        if((j-i)!=(l-k)) return 0;
        if(1+dp[i][j][k][l]) return dp[i][j][k][l];
        if(s1.substr(i,j-i+1)==s2.substr(k,l-k+1)) return dp[i][j][k][l]=1;
        for(int v=1;v<=j-i;v++){
            if(reti(s1,s2,i,v+i-1,k,k+v-1) and reti(s1,s2,v+i,j,k+v,l)) return dp[i][j][k][l]=1;
            if(reti(s1,s2,i,v+i-1,l-v+1,l) and reti(s1,s2,v+i,j,k,l-v)) return dp[i][j][k][l]=1;
        }
        return dp[i][j][k][l]=0;
    }
    bool isScramble(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        if(s1.size()!=s2.size()) return 0;
        return reti(s1,s2,0,s1.size()-1,0,s2.size()-1);
    }
};