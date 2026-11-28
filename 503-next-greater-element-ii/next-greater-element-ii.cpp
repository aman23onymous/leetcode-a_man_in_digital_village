class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n-1;i++){
            nums.push_back(nums[i]);
        }
        stack<int> st;
        for(int i=2*n-2;i>=n;i--){
            while(st.size() and st.top()<=nums[i]){
                st.pop();
            }
            st.push(nums[i]);
        }
        for(int i=n-1;i>=0;i--){
            while(st.size() and st.top()<=nums[i]){
                st.pop();
            }
            if(st.size())ans[i]=st.top();
            st.push(nums[i]);
        }
        return ans;
    }
};