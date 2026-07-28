class Solution {
public:
    vector<vector<int>> adj;
    void dfs(int i,int p,vector<int>& br,vector<int>& nums){
        br[nums[i]]=1;
        for(int x:adj[i]){
            if(x==p) continue;
            dfs(x,i,br,nums);
        }
        // cout<<nums[i]<<" ";
    }
    vector<int> smallestMissingValueSubtree(vector<int>& par, vector<int>& nums) {
        int n=nums.size(),b=-1;
        adj.resize(n);
        for(int i=0;i<nums.size();i++){
            
            if(i){
            adj[par[i]].push_back(i);}
            if(nums[i]==1){
                b=i;
            }
        }
        int mx=1;
        vector<int> ads(n,1),br(100020,0);
        if(-1==b) return ads;
        br[1]=1;
        for(int i:adj[b]){
            dfs(i,b,br,nums);
        }
        while(br[mx]) mx++;
        ads[b]=mx;
        while(par[b]>=0){
            int u=par[b];
            br[nums[u]]=1;
            for(int i:adj[u]){
                if(i==b) continue;
                dfs(i,u,br,nums);
            }
            for(int i=0;i<=8;i++) cout<<br[i]<<" ";
            cout<<mx<<"\n";
            while(br[mx]>0) mx++;
            ads[u]=mx;
            b=u;
        }
        // br[nums[b]]=1;
        // for(int i:adj[b]){
        //     dfs(i,b,br,nums);
        // }
        // while(br[mx]) mx++;
        // ads[b]=mx;
        return ads;
    }
};