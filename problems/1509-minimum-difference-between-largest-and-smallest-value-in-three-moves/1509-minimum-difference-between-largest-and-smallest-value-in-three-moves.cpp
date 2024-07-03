class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int m=INT_MAX,n=nums.size();
        if(n<=4) return 0;
        m=min(m,nums[n-4]-nums[0]);
        m=min(m,nums[n-1]-nums[3]);
        m=min(m,nums[n-2]-nums[2]);
        m=min(m,nums[n-3]-nums[1]);
        return m;
    }
};