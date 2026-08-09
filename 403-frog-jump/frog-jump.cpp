class Solution {
public:
    int dp[2010][2030];
    int reu(int i,vector<int>& stones,int k){
        if(i>=stones.size()-1) return 1;
        if(dp[i][k]+1) return dp[i][k];
        for(int j=i+1;j<stones.size();j++){
            if(stones[i]+k+1<stones[j]) break;
            if(stones[i]+k+1==stones[j] and reu(j,stones,k+1)) return dp[i][k]=1;
            if(stones[i]+k==stones[j] and reu(j,stones,k)) return dp[i][k]=1;
            if(stones[i]+k-1==stones[j] and reu(j,stones,k-1)) return dp[i][k]=1;  
        }
        return dp[i][k]=0;
    }
    bool canCross(vector<int>& stones) {
        int i=0;
        memset(dp,-1,sizeof(dp));
        while(i<stones.size() and stones[0]==stones[i]) i++;
        if(stones[i]!=stones[0]+1) return 0;
        return reu(i,stones,1);
    }
};