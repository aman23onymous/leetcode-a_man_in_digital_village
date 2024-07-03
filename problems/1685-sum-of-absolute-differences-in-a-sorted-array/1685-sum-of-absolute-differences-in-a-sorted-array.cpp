class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> g(nums.size()),f(nums.size());
        g[0]=0,f[nums.size()-1]=0;
        for(int i=0;i<nums.size()-1;i++) g[i+1]=g[i]+nums[i];
        for(int i=nums.size()-1;i>0;i--) f[i-1]=f[i]+nums[i];
        for(int i=0;i<nums.size();i++) nums[i]=f[i]-g[i]+(2*i+1-nums.size())*nums[i];
        return nums;
    }
};