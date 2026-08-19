class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        mp[0]=-1;
        long long s=0,mod=1000000007;
        for(int i=0;i<nums.size();i++){
            s=s+nums[i];
            if(mp.count(s%k)){
                if(i-mp[s%k]>1) return 1;
            }
            else mp[s%k]=i;
        }
        return 0;
    }
};