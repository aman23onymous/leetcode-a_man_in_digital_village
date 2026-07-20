class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> st;
        for(int i:nums){
            auto it=lower_bound(begin(st),end(st),i);
            if(it==st.end()) st.push_back(i);
            else *it=i;
        }
        return st.size();
    }
};