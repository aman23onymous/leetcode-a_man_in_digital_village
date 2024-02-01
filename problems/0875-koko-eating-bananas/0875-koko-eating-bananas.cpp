class Solution {
public:
    bool check(int mid,vector<int> piles, int h){
        int m=mid,n=piles.size(),t=0;
        for(int i=0;i<n;i++){
            // while(piles[i]>0){
            //     piles[i]=piles[i]-m;
            //     t++;
            // }
            int k=piles[i]/m;
            if(piles[i]%m!=0) k++;
            if(t>h) return false;
            t=t+k;
        }
        //cout<<t<<" "<<m<<" ";
        if(t>h) return false;
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int max=-1,i=0,n=piles.size();
        while(i<n){
            if(piles[i]>max) max=piles[i];
            i++;
        }
        int hi=max,lo=1,ans=max;
        while(hi>=lo){
            int mid=lo+(hi-lo)/2;
            if(check(mid,piles,h)){
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return ans;
    }
};