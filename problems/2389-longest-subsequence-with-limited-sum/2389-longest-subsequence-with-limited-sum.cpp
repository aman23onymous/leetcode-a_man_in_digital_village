class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<int> ans(queries.size());
        for(int i=0;i<nums.size()-1;i++){
            nums[i+1]+=nums[i];
        }
        for(int i=0;i<queries.size();i++){
            int len=0;
            for(int j=0;j<nums.size();j++){
                if(nums[j]>queries[i])break;
                else len++;
            }
            ans[i]=len;
        }
        return ans;
    }
};