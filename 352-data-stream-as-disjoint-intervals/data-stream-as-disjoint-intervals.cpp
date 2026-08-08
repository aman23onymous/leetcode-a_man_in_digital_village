class SummaryRanges {
public:
    set<pair<int,int>> st;
    int ad[10002];
    map<int,int> mpb;
    map<int,int> mpa;
    SummaryRanges() {
        memset(ad,0,sizeof(ad));
    }
    void addNum(int val) {
        if(ad[val]) return;
        if(val and ad[val-1] and ad[val+1]){
            st.erase({mpb[val-1],val-1});
            st.erase({val+1,mpa[val+1]});
            ad[val]=1;
            st.insert({mpb[val-1],mpa[val+1]});
            int sr=mpb[val-1],en=mpa[val+1];
            mpb[en]=sr;
            mpa[sr]=en;
            return ;
        }
        if(val and ad[val-1]){
            st.erase({mpb[val-1],val-1});
            ad[val]=1;
            st.insert({mpb[val-1],val});
            int sr=mpb[val-1];
            mpa[sr]=val;
            mpb[val]=sr;
            return;
        }
        if(ad[val+1]){
            st.erase({val+1,mpa[val+1]});
            ad[val]=1;
            st.insert({val,mpa[val+1]});
            int en=mpa[val+1];
            mpa[val]=en;
            mpb[en]=val;
            return;
        }
        ad[val]=1;
        mpa[val]=val;
        mpb[val]=val;
        st.insert({val,val});
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;

        for (auto [l, r] : st) {
            ans.push_back({l, r});
        }

        return ans;

    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */