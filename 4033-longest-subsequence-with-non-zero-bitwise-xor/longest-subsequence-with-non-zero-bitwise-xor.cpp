class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int b=1,x=0,n=nums.size();
        for(int i=0;i<n;i++){
            x^=nums[i];
            if(nums[i]) b=0;
        }
        if(b) return 0;
        if(x) return n;
        return n-1;
    }
};