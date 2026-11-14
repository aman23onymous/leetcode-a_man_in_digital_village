class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int mx=1e9;
        for(int i=0;i<nums.size();i++){
            int s=0;
            for(int j=i;j<nums.size();j++){
                s+=nums[j];
                int ll=j-i+1;
                if(ll>=l and ll<=r and s>0)mx=min(mx,s);
            }
        }
        return mx==1e9?-1:mx;
    }
};