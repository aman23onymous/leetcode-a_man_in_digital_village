class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tmp) {
        stack<int> st;
        vector<int> ans(tmp.size());
        for(int i=tmp.size()-1;i>=0;i--){
            while(st.size() and tmp[i]>=tmp[st.top()]) st.pop();
            ans[i]=0;
            if(st.size()) ans[i]=st.top()-i;
            st.push(i);
        }
        return ans;
    }
};