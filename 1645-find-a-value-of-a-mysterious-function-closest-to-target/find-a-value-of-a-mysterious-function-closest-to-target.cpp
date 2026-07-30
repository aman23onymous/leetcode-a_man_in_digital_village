class Solution {
public:
    void build(vector<int>& arr,vector<int>& seg,int idx,int lo,int hi){
        if(lo==hi) {seg[idx]= arr[lo];return;}
        int m=(lo+hi)/2;
        build(arr,seg,2*idx+1,lo,m);
        build(arr,seg,2*idx+2,m+1,hi);
        seg[idx]=seg[2*idx+1]&seg[2*idx+2];
    }
    int quer(vector<int>& arr,vector<int>& seg,int idx,int lo,int hi,int l,int r){
        if(lo>r or l>hi) return INT_MAX;
        if(lo>=l and hi<=r) return seg[idx];
        int m=(lo+hi)/2;
        int ml=quer(arr,seg,2*idx+1,lo,m,l,r);
        int mr=quer(arr,seg,2*idx+2,m+1,hi,l,r);
        return ml&mr;
    }
    int closestToTarget(vector<int>& arr, int target) {
        int n=arr.size(),mono=1000000000;
        vector<int>seg(4*n+100);
        build(arr,seg,0,0,n-1);
        for(int i=0;i<n;i++){
            int lo=i,hi=n-1,an=INT_MAX,bn=INT_MIN;
            while(lo<=hi){
                int m=(lo+hi)/2;
                int k=quer(arr,seg,0,0,n-1,i,m);
                if(k>target){
                    an=min(an,k);
                    lo=m+1;
                }
                else if(k<target) hi=m-1;
                else{
                    an=k;
                    break;
                }
            }
            lo=i;hi=n-1;
            while(lo<=hi){
                int m=(lo+hi)/2;
                int k=quer(arr,seg,0,0,n-1,i,m);
                if(k>target) lo=m+1;
                else if(k<target) {hi=m-1;
                    bn=max(bn,k);
                }
                else{
                    bn=k;
                    break;
                }
            }
            if(bn!=INT_MIN) mono=min(mono,target-bn);
            if(an!=INT_MAX) mono=min(mono,an-target);
            // mono=min(mono,min(target-bn,an-target));
        }
        return mono;
    }
};