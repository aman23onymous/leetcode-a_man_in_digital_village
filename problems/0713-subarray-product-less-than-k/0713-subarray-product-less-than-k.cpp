class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int i=0,j=0,p=1,n=nums.size(),c=0;
        while(j<n){
            p*=nums[j];
            while(p>=k){
                c+=(j-i);
                p/=nums[i];
                i++;
            }
            j++;
        }
        while(i<n){
            c+=(j-i);
            p/=nums[i++];
        }
        return c; 
    }
};