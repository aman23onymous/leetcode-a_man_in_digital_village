class Solution {
public:
    long long dp[201][201][201],mod=1000000007;
    long long ret(vector<int>& nums,int i,int x,int y){
        if(i<0) return x==y;
        if(1+dp[i][x][y]) return dp[i][x][y];
        long long ans=ret(nums,i-1,x,y)%mod;;
        ans+=ret(nums,i-1,__gcd(x,nums[i]),y);ans%=mod;
        ans+=ret(nums,i-1,x,__gcd(y,nums[i]));ans%=mod;
        return dp[i][x][y]=ans;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return ret(nums,nums.size()-1,0,0)-1;
    }
};