class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rss) {
        sort(begin(rss),end(rss));
        int ans=0;
        for(int i=0;i<rss.size();i++){
            int j=i+1;
            set<int> st;
            st.insert(rss[i][1]);
            while(j<rss.size() and rss[i][0]==rss[j][0]){
                st.insert(rss[j][1]);
                j++;
            }
            if(!(st.count(2) or st.count(3) or st.count(8) or st.count(9) or st.count(4) or st.count(5) or st.count(6) or st.count(7))) ans+=2;
            else if(!(st.count(2) or st.count(3) or st.count(4) or st.count(5))) {ans++;}
            else if(!(st.count(6) or st.count(7) or st.count(8) or st.count(9))) {ans++;}
            else if(!(st.count(4) or st.count(5) or st.count(6) or st.count(7))) {ans++;}
            // cout<<ans<<" ";
            // for(int x:st) cout<<x<<" ";
            if(j<rss.size())ans+=(2*(rss[j][0]-rss[j-1][0]-1));
            cout<<st.size()<<"\n";
            i=j-1;
        }
        return ans+(rss[0][0]*2-2)+(2*(n-rss.back()[0]));
    }
};