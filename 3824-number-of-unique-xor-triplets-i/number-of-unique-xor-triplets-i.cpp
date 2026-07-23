class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        while(n&(n-1)) n=(n&(n-1));
        return 2*n;
    }
};