class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> cnt(31,0);
        for(int x:nums){
            for(int j=0;j<31;j++){
                if(x&(1<<j)) cnt[j]++;
            }
        }
        // for(int i=0;i<4;i++) cout<<cnt[i]<<" ";
        long long ans=0,mod=1000000007;
        for(int i=0;i<k;i++){
            long long b=0;
            for(int j=30;j>=0;j--){
                if(cnt[j]>i) b+=(1ll<<j);
            }
            // cout<<b<<" "; 
            ans+=(b*b);
            ans%=mod;
        }
        return ans;
    }
};