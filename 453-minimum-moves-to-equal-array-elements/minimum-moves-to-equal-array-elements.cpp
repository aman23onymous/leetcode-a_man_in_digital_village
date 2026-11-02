class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = nums[0];
        long long sum = 0; // Use long long to prevent integer overflow during summation
        
        for (int x : nums) {
            mn = min(mn, x);
            sum += x;
        }
        
        // Mathematical equivalent: total sum - (minimum element * array size)
        return sum - (long long)mn * nums.size();

    }
};