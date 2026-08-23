class Solution {
public:
    int par[100005];
    int fin(int u){
        return par[u]=(par[u]==u?u:fin(par[u]));
    }
    void uni(int u,int v){
        par[fin(u)]=fin(v);
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        map<int,int>mp;
        int lim=0;
        for(int i=0;i<100001;i++) par[i]=i;
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i]) and nums[i]>1) uni(i,mp[nums[i]]);
            mp[nums[i]]=i;
            lim=max(lim,nums[i]);
        }
        for(int i=2;i<=lim;i++){
            int b=-1;
            for(int j=i;j<=lim;j+=i){
                if(!mp.count(j)) continue;
                if(1+b) uni(b,mp[j]);
                b=mp[j];
            }
        }
        set<int> st;
        for(int i=0;i<nums.size();i++) {st.insert(fin(i));}
        return st.size()==1;
    }
};