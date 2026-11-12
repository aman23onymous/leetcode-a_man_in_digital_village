class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        map<int,int>mp;
        int n=row.size();
        for(int i=0;i<n;i++){
            mp[row[i]]=i;
        }
        int ans=0;
        set<int> st;
        for(int i=0;i<n;i++){
            if(st.count(i/2)) continue;
            int a=row[i],t=i/2,k=0;
            while(st.count(t)==0){
                st.insert(t);
                int b=((a/2)*2)*2+1-a;
                if(mp[b]%2) a=row[mp[b]-1];
                else a=row[mp[b]+1];
                t=mp[b]/2;
                k++;
            }
            cout<<k<<" ";
            ans+=(k-1);
        }
        return ans;
    }
};