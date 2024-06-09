class Solution {
public:
    int minSubArrayLen(int tar, vector<int>& arr) {
        int minln=INT_MAX,n=arr.size(),ln,sum=0;
        int i=0,j=0;
        while(j<n){
            sum+=arr[j];
            while(sum>=tar){
                ln=j-i+1;
                minln=min(ln,minln);
                sum-=arr[i];
                i++;
            }
            j++;
        }
        if(minln==INT_MAX) return 0;
        return minln;
    }
};