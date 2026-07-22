class Solution {
public:
    int seg[400001];
    void build(vector<int>&nums,int idx,int lo,int hi){
        if(lo==hi){
            seg[idx]=nums[lo];
            return;
        }
        int md=(lo+hi)/2;
        build(nums,idx*2+1,lo,md);
        build(nums,idx*2+2,md+1,hi);
        seg[idx]=max(seg[idx*2+1],seg[2*idx+2]);
    }
    int query(int l,int r,int idx,int lo,int hi){
        if(lo>r or hi<l) return 0;
        if(lo>=l and hi<=r) return seg[idx];
        int md=(lo+hi)/2;
        return max(query(l,r,idx*2+1,lo,md),query(l,r,idx*2+2,md+1,hi));
    }
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& q) {
        vector<int> zb,zr,zl,ans,nums;
        int c1=0,n=s.size();
        for(int i=0;i<n;i++) c1+=(s[i]-'0');
        for(int i=0;i<n;i++){
            int j=i;
            while(j<n and s[i]==s[j]) j++;
            if('1'-s[i]){
                zl.push_back(i);
                zr.push_back(j-1);
                zb.push_back(j-i);
            }
            i=j-1;
        }
        if(zl.size()<=1){
            for(auto x:q){
                ans.push_back(c1);
            }
            return ans;
        }
        int m=zb.size();
        for(int i=0;i<m-1;i++){
            nums.push_back(zb[i]+zb[i+1]);
        }
        build(nums,0,0,m-2);
        for(auto x:q){
            int lidx=lower_bound(begin(zr),end(zr),x[0])-begin(zr);
            int ridx=upper_bound(begin(zl),end(zl),x[1])-begin(zl)-1;
            if(lidx>=ridx or lidx>=m or ridx<0){
                ans.push_back(c1);
                continue;
            }
            int fl=zr[lidx]-max(zl[lidx],x[0])+1;
            int ll=min(zr[ridx],x[1])-zl[ridx]+1;
            if(lidx==ridx-1){
                ans.push_back(c1+fl+ll);
                continue;
            }
            ans.push_back(c1+max(max(fl+zb[lidx+1],ll+zb[ridx-1]),query(lidx+1,ridx-2,0,0,m-2)));
        }
        return ans;
    }
};