class Solution {
public:
    int totalHammingDistance(std::vector<int>& nums) {
    int totalDistance = 0;
    int n = nums.size();
    for (int bit = 0; bit < 32; bit++) {
        int countOnes = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] & (1 << bit)) {
                countOnes++;
            }
        }
        int countZeros = n - countOnes;
        totalDistance += countOnes * countZeros;
    }
    return totalDistance;
}
};