class Solution {
public:
    map<pair<int,int>,int>mp;
    int ddd(vector<vector<int>>& cc,int i,int d){
        if(i>=cc.size()) return 0;
        if(mp.count({i,d})) return mp[{i,d}];
        int mx=ddd(cc,i+1,d);
        if(d+cc[i][0]<=cc[i][1]){
            mx=max(mx,1+ddd(cc,i+1,d+cc[i][0]));
        }
        return mp[{i,d}]=mx;
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        // memset(dp,-1,sizeof(dp));
        sort(begin(courses),end(courses),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        int dd=0;
        priority_queue<int> pq;
        for(auto x:courses){
            dd+=x[0];
            pq.push(x[0]);
            if(x[1]<dd){
                dd-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};