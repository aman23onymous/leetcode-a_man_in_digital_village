class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int mx=-1;
        for(int i=0;i<nums.size();i++) mx=max(mx,nums[i]);
        int s=0;
        for(int i=0;i<k;i++,mx++) s+=mx;
        return s;
    }
};