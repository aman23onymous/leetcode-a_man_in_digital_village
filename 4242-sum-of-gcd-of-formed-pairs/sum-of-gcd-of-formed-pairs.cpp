class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<long long> x(nums.size());
        long long mx=0,s=0;
        for(int i=0;i<nums.size();i++){
            mx=max(mx,1LL*nums[i]);
            x[i]=__gcd(mx,1ll*nums[i]);
        }
        sort(begin(x),end(x));
        for(int i=0;i<(nums.size())/2;i++){
            s+=__gcd(x[i],x[nums.size()-1-i]);
        }
        return s;
    }
};