class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mx=*max_element(begin(nums),end(nums)),mn=*min_element(begin(nums),end(nums)),l=0;
        for(int i=0;i<nums.size();i++){
            if(mx==nums[i] or mn==nums[i]) continue;
            int j=i;
            while(j<nums.size() and !(mx==nums[j] or mn==nums[j]))j++;
            l=max(l,j-i);
            i=j-1;
        }
        return nums.size()-l;
    }
};