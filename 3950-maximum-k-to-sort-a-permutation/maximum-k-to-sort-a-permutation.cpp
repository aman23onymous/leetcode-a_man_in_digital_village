class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int mx=(1<<28)-1;
        for(int i=0;i<nums.size();i++){
            if(i!=nums[i]) {mx=mx&nums[i];}
        }
        return mx==((1<<28)-1)?0:mx;;
    }
};