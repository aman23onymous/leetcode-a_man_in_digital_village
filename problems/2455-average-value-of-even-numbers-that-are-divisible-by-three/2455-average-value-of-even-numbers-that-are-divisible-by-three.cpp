class Solution {
public:
    int averageValue(vector<int>& nums) {
        
        int x=0,s=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%6==0) x++,s+=nums[i];
            }
            if(s==0  ) return 0;
            return s/x;
    }
};