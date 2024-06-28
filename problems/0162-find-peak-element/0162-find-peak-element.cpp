class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo=1,hi=nums.size()-2;
        if(hi==-1) return 0;
        if(nums[0]>nums[1]) return 0;
        // cout<<0;
        if(nums[hi+1]>nums[hi]) return hi+1;
        while(hi>=lo){
            int m=(hi+lo)/2;
            if(nums[m]>nums[m-1]&&nums[m]>nums[m+1]) return m;
            else if(nums[m]>nums[m-1]) lo=m+1;
            else hi=m-1;
        }
        return hi;
    }
};