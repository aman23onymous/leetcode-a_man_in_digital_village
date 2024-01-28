class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> p;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i+=1){
            if(nums[i]==target) p.push_back(i);
        }
        //sort(p.begin(),p.end());
        return p;
    }
};