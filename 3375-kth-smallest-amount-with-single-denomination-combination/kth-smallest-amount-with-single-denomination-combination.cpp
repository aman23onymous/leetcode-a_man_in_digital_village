class Solution {
public:
    
    long long lcm(long long a, long long b){
        return (a / __gcd(a,b)) * b;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        vector<vector<long long>> ad(n+1);

        for(int i=1;i<(1<<n);i++){
            vector<long long> a;
            for(int j=0;j<n;j++){
                if(i&(1<<j)) a.push_back(coins[j]);
            }

            long long cur = a[0];
            for(int j=1;j<a.size();j++){
                cur = lcm(cur, a[j]);
                if(cur > 2e15) break;
            }
            if(cur <= 2e15)
                ad[a.size()].push_back(cur);
        }

        long long lo=1, hi=2e15, ans=0;

        while(lo<=hi){
            long long m=(lo+hi)/2;
            long long cnt=0;

            for(int i=1;i<=n;i++){
                for(auto x:ad[i]){
                    if(i%2) cnt += (m/x);
                    else cnt -= (m/x);
                }
            }

            if(cnt >= k){
                ans = m;
                hi = m-1;
            }
            else lo = m+1;
        }

        return ans;
    }
};