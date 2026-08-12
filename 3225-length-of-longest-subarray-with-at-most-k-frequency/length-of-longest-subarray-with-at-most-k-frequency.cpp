class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        int mx=0;
        for(int i=0,j=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>k) {
                while(nums[i]!=nums[j]){
                    mp[nums[j]]--;
                    j++;
                }
                mp[nums[j]]--;
                    j++;
            }
            // cout<<i<<" "<<j<<"\n";
            mx=max(mx,i-j+1);
        }
        return mx;
    }
};