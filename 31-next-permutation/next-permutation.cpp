class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                int j=n-1;
                while(j>i and nums[i]>=nums[j]) j--;
                swap(nums[j],nums[i]);
                reverse(begin(nums)+i+1,end(nums));
                return;
            }
        }
        reverse(begin(nums),end(nums));
        return;
    }
};