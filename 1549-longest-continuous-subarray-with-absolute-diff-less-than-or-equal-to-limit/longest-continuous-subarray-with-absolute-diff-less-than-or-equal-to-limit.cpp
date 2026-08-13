class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
    multiset<int> st;
    int mx=1,n=nums.size();
    for(int i=0,j=0;i<n;i++){
        st.insert(nums[i]);
        while(st.size() and (*st.rbegin()-*st.begin())>limit){
            auto it =st.find(nums[j]);
            st.erase(it);
            j++;
        }
        mx=max(mx,i-j+1);
    }
    return mx;
}

};