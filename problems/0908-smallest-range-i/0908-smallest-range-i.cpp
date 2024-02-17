class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        // int i=0;
        // while(i<=k&&nums[0]<=nums[nums.size()-1]){
        //     nums[0]+=i;
        //     nums[nums.size()-1]-=i;
        //     i++;
        // }
        if(nums[nums.size()-1]-nums[0]-2*k<0) return 0;
        return nums[nums.size()-1]-nums[0]-2*k;
    }
};