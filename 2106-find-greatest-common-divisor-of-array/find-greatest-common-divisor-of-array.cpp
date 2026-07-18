class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(begin(nums),end(nums));
        return __gcd(nums.back(),nums[0]);
    }
};