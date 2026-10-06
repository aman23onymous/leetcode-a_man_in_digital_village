class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int a=0;
        for(auto&x:s){
            if(x=='(') st.push(x);
            else if(st.size()) st.pop();
            else a++;
        }
        return st.size()+a;
    }
};