class Solution {
public:
    int trap(vector<int>& ht) {
        stack<int> st;
        int ans=0;
        for(int i=0;i<ht.size();i++){
            while(st.size() and ht[st.top()]<ht[i]){
                int h=ht[st.top()];st.pop();
                if(st.size()==0)break;
                ans+=((min(ht[st.top()],ht[i])-h)*(i-st.top()-1));
                    cout<<i<<" "<<(min(ht[st.top()],ht[i]))<<"\n";
                // st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};