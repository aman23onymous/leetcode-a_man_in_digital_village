// OLDER CODE
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int sum=0;
//         for(int i=0;i<nums.size();i++){
//             sum+=nums[i];
//         }
//         return (nums.size())*(nums.size()+1)/2-sum;
//     }
// };
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        while(i<n){
            if(nums[i]==n||i==nums[i]) i++;
            else swap(nums[nums[i]],nums[i]); 
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i) return i;
        }
        return n;
    }
};