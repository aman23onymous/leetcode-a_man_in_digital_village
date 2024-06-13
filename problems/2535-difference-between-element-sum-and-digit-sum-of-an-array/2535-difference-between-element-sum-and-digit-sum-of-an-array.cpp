class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int a=0;
        for(int i=0;i<nums.size();i++) a+=nums[i];
        int b=0;
        for(int i=0;i<nums.size();i++){
            while(nums[i]>0){
                b+=(nums[i]%10);
                nums[i]/=10;
            }
        }
        return a-b;
    }
};