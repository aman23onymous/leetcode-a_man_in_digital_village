class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // for(int i=1;i<nums.size();i++){
        //     for(int j=i;j>0&&nums[j]<nums[j-1];j++){
        //         swap(nums[j],nums[j-1]);
        //     }
        // }
        sort(nums.begin(),nums.end());
        // int i,n=1;
        // for(i=1;i<nums.size();i++){
        //     if(nums[i]==nums[i-1]) n++;
        //     else n=1;
        //     if (n==nums.size()/2+1) break;
        // }
        return nums[nums.size()/2];
    }
};