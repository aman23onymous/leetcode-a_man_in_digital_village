class Solution {
public:
    long long power(long long a, long long b)
{
    long long res = 1,MOD=1000000007;
    while (b)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
    long long dp[101][102][103];
    long long reti(int i,int k,int l,vector<int>&nums){
        if(k==0) return power(2,l);
        if(i<0) return 0;
        if(1+dp[i][k][l]) return dp[i][k][l];
        long long mx=0,mod=1000000007;
        for(int j=i;j>=0;j--){
            if(nums[j]>k) continue;
            mx+=reti(j-1,k-nums[j],l-1,nums);mx%=mod;
        }
        return dp[i][k][l]=mx;
    }
    int sumOfPower(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        int i=nums.size()-1;
        return reti(nums.size()-1,k,nums.size(),nums);
    }
};