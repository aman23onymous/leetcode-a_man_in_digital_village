class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int i=0,j=1;
        vector<int> m;
        sort(nums.begin(),nums.end());
        while(j<nums.size()){
            if(nums[i]==nums[j]){
                j++;
            }
            else{
                if((j-i)>nums.size()/3) m.push_back(nums[i]);
                i=j++;
            }
        }
        if((j-i)>nums.size()/3) m.push_back(nums[i]);
        return m;
    }
};