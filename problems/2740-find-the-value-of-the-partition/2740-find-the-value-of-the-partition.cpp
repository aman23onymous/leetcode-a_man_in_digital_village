class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mn=2000000000;
        for(int i=0;i<nums.size()-1;i++) mn=min(mn,-nums[i]+nums[i+1]);
        return mn;
    }
};