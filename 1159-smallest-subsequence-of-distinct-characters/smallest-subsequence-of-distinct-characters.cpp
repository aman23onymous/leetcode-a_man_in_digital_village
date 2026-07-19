class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> st;
        map<char,int> mp,mb;
        for(auto x:s) mp[x]++;
        for(int i=0;i<s.size();i++){
            mp[s[i]]--;
            if(mb[s[i]]>0) continue;
            while(st.size() and st.top()>s[i] and mp[st.top()]>0 ){
                mb[st.top()]--;
                st.pop();
            }
            st.push(s[i]);
            mb[s[i]]++;
        }
        string b="";
        while(st.size()){
            b.push_back(st.top());
            st.pop();
        }
        reverse(begin(b),end(b));
        return b.substr(0,mp.size());
    }
};