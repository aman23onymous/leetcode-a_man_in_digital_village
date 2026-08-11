class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int i=1,s=nums[0];
        while(i<nums.size() and nums[i]==nums[i-1]+1){
            s+=nums[i];
            i++;
        }
        set<int> st(begin(nums),end(nums));
        for(int x:st){
            s+=(x==s);
        }
        return s;
    }
};