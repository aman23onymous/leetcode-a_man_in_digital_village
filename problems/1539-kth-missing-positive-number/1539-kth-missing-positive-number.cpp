class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int lo=0,hi=arr.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int c=arr[mid]-mid-1;
            if(c>=k){
                hi=mid-1;
            }else{
                lo = mid + 1;
            }
        }
        return k+lo;
    }
};