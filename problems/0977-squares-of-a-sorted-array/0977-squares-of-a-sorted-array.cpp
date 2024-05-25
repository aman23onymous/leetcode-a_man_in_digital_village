class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> k(nums.size());
        for(int i=0;i<nums.size();i++){
            k[i]=nums[i]*nums[i];
        }
        sort(k.begin(),k.end());
        return k;
    }
};