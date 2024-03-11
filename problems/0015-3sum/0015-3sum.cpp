class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> p;
        int n=nums.size();
        vector<vector<int>> k;
        for(int i=0;i<n-2;i++){
            int lo=i+1,hi=n-1;
            while(hi>lo){
                if(nums[i]+nums[lo]+nums[hi]==0){
                    p.push_back(nums[i]);
                    p.push_back(nums[lo]);
                    p.push_back(nums[hi]);
                    k.push_back(p);
                    p.pop_back();
                    p.pop_back();
                    p.pop_back();
                    while (lo < hi && nums[lo] == nums[lo + 1]) lo++;
                    while (lo < hi && nums[hi] == nums[hi - 1]) hi--;
                    lo++,hi--;
                }
                else if(nums[i]+nums[lo]+nums[hi]>0) hi--;
                else lo++;
            }
            while (i < n - 2 && nums[i] == nums[i + 1]) i++;
        }
        return k;
    }
};