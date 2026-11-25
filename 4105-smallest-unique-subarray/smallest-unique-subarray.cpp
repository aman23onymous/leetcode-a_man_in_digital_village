class Solution {
public:
    long long pow[100002],p=100002,mod=1000000007;
    long long mix(vector<int>& nums,int b){
        long long cur=0;
        for(int i=0;i<b;i++) cur=(cur*p+nums[i])%mod;
        map<int,int>mp;
        mp[cur]++;
        for(int i=b;i<nums.size();i++){
            cur=(cur-(nums[i-b]*pow[b-1])%mod+mod)%mod;
            cur=(cur*p+nums[i])%mod;
            mp[cur]++;
        }
        for(auto [x,y]:mp){
            if(y==1) return 1;
        }
        return 0;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        pow[0]=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pow[i+1]=(pow[i]*p)%mod;
        }
        int lo=1,hi=n,ans=n;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(mix(nums,mid)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};