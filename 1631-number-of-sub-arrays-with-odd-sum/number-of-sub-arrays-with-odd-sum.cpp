class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int l[2]={0},s=0,ans=0,mod=1000000007;
        l[0]=1;
        for(int x:arr){
            s+=x;
            if(s%2) ans+=l[0];
            else ans+=l[1];
            l[s%2]++;
            ans%=mod;
        }
        return ans;
    }
};