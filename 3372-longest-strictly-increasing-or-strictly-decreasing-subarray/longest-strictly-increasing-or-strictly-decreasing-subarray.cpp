class Solution {
public:
    int longestMonotonicSubarray(vector<int>& a) {
        int i=0,mx=1,n=a.size();
        while(i<n-1){
            int j=i;
            while(j<n-1 and a[j]==a[j+1]) j++;
            i=j;
            if(j<n-1 and a[j]<a[j+1])while(j<n-1 and a[j]<a[j+1]) j++;
            else while(j<n-1 and a[j]>a[j+1]) j++;
            cout<<j<<"\n";
            mx=max(mx,j-i+1);
            i=j;
        }
        return mx;
    }
};