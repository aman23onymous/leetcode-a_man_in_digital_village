class Solution {
public:
    bool check(int mid,vector<int>& wts,int d){
        int m=mid,n=wts.size(),count=0;
        for(int i=0;i<n;i++){
            if(m>=wts[i]){
                m-=wts[i];
            }else{
                count++;
                m=mid;
                m-=wts[i];
            }
        }
        if(count>=d) return false;
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int mx=-5,sum=0;
        for(int i=0;i<weights.size();i++){
            if(mx<weights[i]) mx=weights[i];
            sum+=weights[i];
        }
        cout<<mx<<" "<<sum;
        int lo=mx,ans=sum,hi=sum;
        while(hi>=lo){
            int mid=lo+(hi-lo)/2;
            if(check(mid,weights,days)){
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return ans;
    }
};