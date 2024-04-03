class Solution {
public:
    void addsub(int i,vector<vector<int>> &v,vector<int>& nums,vector<int>& n){
        if(nums.size()==i){
            v.push_back(n);
            return;
        }
        addsub(i+1,v,nums,n);
        n.push_back(nums[i]);
        addsub(i+1,v,nums,n);
        n.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> n;
        addsub(0,v,nums,n);
        return v;
    }
};