class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int mx=-45,mn=678;
        for(int i=0;i<nums.size();i++){
            mx=max(nums[i],mx);
            mn=min(nums[i],mn);
        }
        for(int i=0;i<nums.size();i++){
            if(mx!=nums[i]&&mn!=nums[i]) return nums[i];
        }
        return -1;
    }
};