class Solution {
public:
    // int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int maxSatisfied(vector<int>& arr, vector<int>& grumpy, int m) {
        int sum=0,mxsum=-1,mxi=0,k=m,n=arr.size();
        for(int i=0;i<k;i++) if(grumpy[i]==1)sum+=arr[i];
        mxsum=sum;
        int i=1,j=k;
        while(j<n){
            if(grumpy[j]==1&&grumpy[i-1]==1) sum+=arr[j]-arr[i-1];
            else if(grumpy[j]==0&&grumpy[i-1]==1) sum-=arr[i-1];
            else if(grumpy[j]==1&&grumpy[i-1]==0) sum+=arr[j];

            if(mxsum<sum){
                mxsum=sum;
                mxi=i;
            }
            i++,j++;
        }
        cout<<mxsum<<"  "<<mxi<<endl;
        for(int a=mxi;a<mxi+k;a++) grumpy[a]=0;
        int c=0;
        // for(int a=0;a<n;a++) cout<<grumpy[a]<<"  ";
        for(int a=0;a<n;a++){
            if(grumpy[a]==0) c+=arr[a];
        }
        return c;
    
    }
};