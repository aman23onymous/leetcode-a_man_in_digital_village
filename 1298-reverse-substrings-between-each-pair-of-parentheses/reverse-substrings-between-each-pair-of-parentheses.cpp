class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                queue<char>ts;
                while(st.size() and st.top()!='('){
                    ts.push(st.top());
                    st.pop();
                }
                st.pop();
                while(ts.size()){
                    st.push(ts.front());
                    ts.pop();
                }
            }
            else st.push(s[i]);
        }
        string ans="";
        while(st.size()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};