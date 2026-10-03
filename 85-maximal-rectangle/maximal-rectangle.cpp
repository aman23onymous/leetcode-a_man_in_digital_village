class Solution {
public:
    int reti(vector<int>&a){
        int n=a.size(),mx=0;
        stack<int> st;
        vector<int> prn(n,-1),nxt(n,n);
        for(int i=0;i<n;i++){
            // cout<<a[i]<<" ";
            while(st.size() and a[st.top()]>=a[i]) st.pop();
            if(st.size()) prn[i]=st.top();
            st.push(i);
        }
        while(st.size()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(st.size() and a[st.top()]>=a[i]) st.pop();
            if(st.size()) nxt[i]=st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++){
            // cout<<nxt[i]<<" "<<prn[i]<<"\n";
            mx=max(mx,a[i]*(nxt[i]-prn[i]-1));
        }
        return mx;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int n=mat.size(),m=mat[0].size(),mx=0;
        vector<int> a(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[j][i]=='0') a[j]=0;
                else a[j]++;
                // cout<<a[j]<<" ";
            }
            // cout<<"\n";
            mx=max(mx,reti(a));
        }
        return mx;
    }
};