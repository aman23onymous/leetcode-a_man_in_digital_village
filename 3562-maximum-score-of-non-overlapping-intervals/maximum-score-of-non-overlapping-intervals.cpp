class Solution {
public:
    int minz[100000];
    map<int,pair<long long,vector<int>>>mp;
    pair<long long,vector<int>> mi_haarli_re(vector<vector<int>>& intervals,int i,int k){
        if(k==0 or i<0) return {0,{}};
        if(mp.count(i*10+k)) return mp[i*10+k];
        long long mx=0;
        vector<int> b;
        auto [x,y]=mi_haarli_re(intervals,i-1,k);
        if(mx<=x){
            mx=x;
            b=y;
        }
        auto [w,z]=mi_haarli_re(intervals,minz[i],k-1);
        if(mx < 1LL*w+intervals[i][2]){
    mx = w+intervals[i][2];
    b = z;
    b.push_back(intervals[i][3]);
    sort(b.begin(), b.end());
}
else if(mx == w+intervals[i][2]){
    vector<int> temp = z;
    temp.push_back(intervals[i][3]);
    sort(b.begin(), b.end());
    if(temp < b){
        b = temp;
        sort(b.begin(), b.end());
    }
}
        return mp[i*10+k]={mx,b};
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n=intervals.size();
        for(int i=0;i<n;i++){
            intervals[i].push_back(i);
            // cout<<minz[i]<<" ";
        }
        sort(begin(intervals),end(intervals),[](vector<int>&a,vector<int>&b){
            if(a[1]==b[1]) return a[0]<b[0];
            return a[1]<b[1];
        });
        minz[0]=-1;
        // int n=intervals.size();
        for(int i=1;i<n;i++){
            int lo=0,hi=i-1;
            minz[i]=-1;
            while(lo<=hi){
                int m=(lo+hi)/2;
                if(intervals[i][0]>intervals[m][1]){
                    minz[i]=m;
                    lo=m+1;
                }
                else hi=m-1;
            }
            // cout<<minz[i]<<" ";
        }
        for(auto x:intervals){
            // cout<<x[0]<<" "<<x[1]<<"\n";
        }
        return mi_haarli_re(intervals,n-1,4).second;
    }
};