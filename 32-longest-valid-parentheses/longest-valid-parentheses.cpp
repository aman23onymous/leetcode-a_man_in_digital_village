class Solution {
public:
    int longestValidParentheses(string s) {
        int mx=0;
        stack<int> st;
        vector<int> x(s.size(),0);
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push(i);
            else{
                if(st.size()){
                    x[i]=1;
                    x[st.top()]=1;
                    st.pop();
                }
            }
        }
        for(int i=0;i<s.size();i++){
            if(x[i]==1){
                int j=i;
                while(j<s.size()&&x[j]==1) j++;
                mx=max(mx,j-i);
            }
        }
        return mx;
    }
};