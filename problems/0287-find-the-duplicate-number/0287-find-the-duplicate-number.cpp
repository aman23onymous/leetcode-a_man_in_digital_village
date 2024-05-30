class Solution {
public:
/////THIS METHOD ALTERS THE ARRAY///SO THE SUM METHOD IS MORE BETTER;
    int findDuplicate(vector<int>& nums) {
        int n=nums.size(),i=0;//
        while(i<n){
            if(nums[i]==nums[nums[i]]) return nums[i];
            else swap(nums[i],nums[nums[i]]);
        }
        return n;
    }
};