class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<int>> a;
        for(int i=0;i<n;i++){
            a.push_back({efficiency[i],speed[i]});
        }
        sort(begin(a),end(a));
        // for(auto x:a){
        //     cout<<x[0]<<" "<<x[1]<<"\n";
        // }
        priority_queue<int,vector<int>,greater<int>> pq;
        long long ans=0,mod=1000000007,s=0;
        for(int i=n-1;i>=0;i--){
            pq.push(a[i][1]);
            s+=a[i][1];
            if(pq.size()>k){
                s-=pq.top();
                pq.pop();
            }
            // cout<<s<<" ";
            ans=max(ans,a[i][0]*s);
        }
        return ans%mod;
    }
};