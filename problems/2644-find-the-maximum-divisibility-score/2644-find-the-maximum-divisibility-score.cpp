class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
    int n = nums.size(), m = divisors.size();
    vector<int> a(m, 0);
    
    // Calculate the division scores
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (nums[j] % divisors[i] == 0) {
                a[i]++;
            }
        }
    }
    
    int x = -1, p = -1;
    
    // Find the maximum division score and the smallest divisor
    for (int i = 0; i < m; i++) {
        if (a[i] > x) {
            x = a[i];
            p = i;
        } else if (a[i] == x && divisors[i] < divisors[p]) {
            p = i;
        }
    }
    
    return divisors[p];
}
    
};