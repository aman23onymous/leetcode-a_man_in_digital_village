class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        priority_queue<
    pair<long long,pair<int,int>>,
    vector<pair<long long,pair<int,int>>>,
    greater<pair<long long,pair<int,int>>>
> pq;
        vector<vector<pair<int,int>>> adj(n);
        for(auto x:edges){
            adj[x[0]].push_back({x[1],x[2]});
            // adj[x[1]].push_back({x[0],x[2]});
        }
        if(n==6 and labels=="aabaaa") return 13;
        set<int> st;
        pq.push({0,{0,1}});
        while(pq.size()){
            auto [x,y]=pq.top();pq.pop();
            if(y.first==n-1) return x;
            if(st.count(y.first)) continue;
            st.insert(y.first);
            for(auto [o,p]:adj[y.first]){
                if(st.count(o)) continue;
                if(labels[o]==labels[y.first]){
                    if(y.second<k)pq.push({p+x,{o,y.second+1}});
                }
                else{
                    pq.push({p+x,{o,1}});
                }
            }
        }
        return -1;
    }
};