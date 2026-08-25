class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> st;
        for(int x:nums) st.insert(x);
        for(int i=k;;i+=k){
            if(st.count(i)) continue;
            return i;
        }
        return 0;
    }
};