class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long>a(n+4,1e14);
        a[0]=0;
        for(int i=0;i<n;i++){
            a[i+1]=min(a[i+1],costs[i]+a[i]+1);
            if(i+1<n)a[i+2]=min(a[i+2],costs[i+1]+a[i]+4);
            if(i+2<n)a[i+3]=min(a[i+3],costs[i+2]+a[i]+9);
        }
        return a[n];
    }
};