class Solution {
public:
    
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st,st2,st3;

        for(int i = 0; i < n; i++) {
            st.insert(nums[i]);
            for(int x:st){
                st2.insert(x^nums[i]);
            }
            for(int x:st2){
                st3.insert(x^nums[i]);
            }
        }

        return st3.size();
    }
};
