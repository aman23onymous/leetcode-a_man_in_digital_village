class Solution {
public:
    int sol(vector<vector<int>>&dp,string s, string t,int i,int j){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j]=sol(dp,s,t,i-1,j-1)+sol(dp,s,t,i-1,j);
        return dp[i][j]=sol(dp,s,t,i-1,j);
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+5,vector<int>(t.size()+2,-1));
        return sol(dp,s,t,s.size()-1,t.size()-1);
    }
};