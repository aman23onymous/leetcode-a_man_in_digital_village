class Solution {
public:
    int distinctEchoSubstrings(string text) {
        long long n=text.size(),mod=1000000007,mod1=1000000009,ans=0;
        set<string> st;
        vector<long long> as(n,text[0]-'a'),bs(n+1,1),cs(n,text[0]-'a'),ds(n+1,1);
        for(int i=1;i<n;i++) {as[i]=(as[i-1]*26+text[i]-'a')%mod;bs[i]=(bs[i-1]*26)%mod;}
        for(int i=1;i<n;i++) {cs[i]=(cs[i-1]*26+text[i]-'a')%mod1;ds[i]=(ds[i-1]*26)%mod1;}
        auto gethash=[&](int a,int b){
            if(a) return (as[b]-(as[a-1]*bs[1+b-a])%mod+mod)%mod;
            return as[b];
        };
        auto gethash1=[&](int a,int b){
            if(a) return (cs[b]-(cs[a-1]*ds[1+b-a])%mod1+mod1)%mod1;
            return cs[b];
        };
        for(int i=0;i<n;i++){
            for(int j=1;j*2+i<=n;j++){
                if(gethash(i,i+j-1)==gethash(i+j,i+2*j-1) and gethash1(i,i+j-1)==gethash1(i+j,i+2*j-1)) {
                    // cout<<text.substr(i,2*j)<<" ";
                    st.insert(text.substr(i,2*j));}
            }
        }
        for(auto x:st) cout<<x<<" ";
        return st.size();
        return ans;
    }
};