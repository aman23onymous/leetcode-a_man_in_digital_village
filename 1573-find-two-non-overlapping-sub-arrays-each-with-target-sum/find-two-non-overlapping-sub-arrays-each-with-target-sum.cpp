class Solution {
public:
    int calc[100004][4];
    int dp(vector<vector<int>>&win,int i,int l){
        if(l==0) return 0;
        if(i<0) return 1e9;
        if(1+calc[i][l]) return calc[i][l];
        int mn=1e9;
        mn=min(mn,dp(win,i-1,l));
        int lo=0,hi=i-1,b=-1;
        while(lo<=hi){
            int m=(lo+hi)/2;
            if(win[m][1]<win[i][0]) {lo=m+1;b=m;}
            else hi=m-1;
        }
        mn=min(mn,win[i][1]-win[i][0]+1+dp(win,b,l-1));
        return calc[i][l]=mn;
    }
    int minSumOfLengths(vector<int>& arr, int target) {
        int s=0;
        map<int,int> mp;
        mp[s]=-1;
        vector<vector<int>> a;
        for(int i=0;i<arr.size();i++){
            s+=arr[i];
            mp[s]=i;
            if(mp.count(s-target)) a.push_back({mp[s-target]+1,i});
        }
        memset(calc,-1,sizeof(calc));
        int an= dp(a,a.size()-1,2);
        if(1000000000!=an) return an;
        return -1;
    }
};