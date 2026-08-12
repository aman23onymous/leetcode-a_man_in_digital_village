class Solution {
public:
    int br;
    vector<long long> dis(int src,vector<vector<vector<int>>>&adj){
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>> pq;
        pq.push({0,src});
        vector<long long> k(adj.size(),1e12);
        while(pq.size()){
            auto x=pq.top();pq.pop();
            if((x[0])>=k[x[1]]) continue;
            k[x[1]]=x[0];
            for(auto y:adj[x[1]]){
                if(k[y[0]]<x[0]) continue;
                pq.push({y[1]+x[0],y[0]});
            }
        }
        return k;
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        
    vector<vector<vector<int>>> adj(n);
    vector<vector<vector<int>>> bdj(n);
        br=edges.size();
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2],i});
            bdj[edges[i][1]].push_back({edges[i][0],edges[i][2],i});
        }
        vector<long long> k=dis(src1,adj);
        vector<long long> l=dis(src2,adj);
        vector<long long> m=dis(dest,bdj);
        long long mx=1e12;
        for(int i=0;i<n;i++){
            mx=min(mx,k[i]+l[i]+m[i]);
        }
        return mx==1e12?-1:mx;
    }
};