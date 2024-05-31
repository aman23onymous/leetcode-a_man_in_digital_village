class Solution {
public:
    int minimumSum(vector<int>& nums) {
        vector<int> s;
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                for(int k=j+1;k<nums.size();k++){
                    if(nums[j]>nums[i]&&nums[j]>nums[k]) s.push_back(nums[i]+nums[j]+nums[k]);
                }
            }
        }
        if(s.empty()) return -1;
        cout<<s.size()<<" "<<s[0];
        sort(s.begin(),s.end());
        return s[0];
    }
};