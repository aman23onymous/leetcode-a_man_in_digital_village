class Solution {
public:
    unordered_map<int,int> dp;
    int mxi(vector<int>& sv,int i){
        if(i==sv.size()) return 0;
        if(dp.count(i)) return dp[i];
        int mx=-1e9;
        mx=max(mx,sv[i]-mxi(sv,i+1));
        if(i+1<sv.size()) mx=max(mx,sv[i]+sv[i+1]-mxi(sv,i+2));
        if(i+2<sv.size()) mx=max(mx,sv[i]+sv[i+1]+sv[i+2]-mxi(sv,i+3));
        if(i==0)cout<<mx;
        return dp[i]=mx;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int su=accumulate(begin(stoneValue),end(stoneValue),0),ti=mxi(stoneValue,0);
        cout<<ti;
        dp.clear();
        if(0==ti) return "Tie";
        if(0>ti) return "Bob";
        return "Alice";
    }
};