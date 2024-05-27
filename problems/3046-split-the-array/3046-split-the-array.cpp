class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        vector<int> num(100,0);
        for(int i=0;i<nums.size();i++) num[nums[i]-1]++;
        for(int i=0;i<100;i++) if(num[i]>2) return false;
        return true;
    }
};