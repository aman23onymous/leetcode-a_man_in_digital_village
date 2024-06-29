class Solution {
public:
    int sumD(vector<int>& nums, int t){
        int x=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%t==0) x+=(nums[i]/t);
            else x+=((nums[i]/t)+1);
        }
        return x;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        if(n>threshold) return -1;
        int lo=1,hi=-1;
        for(int i=0;i<n;i++) hi=max(hi,nums[i]);
        while(hi>=lo){
        // cout<<hi;
            int m=(lo+hi)/2;
            if(sumD(nums,m)<=threshold) hi=m-1;
            else lo = m+1;
        }
        return lo;
    }
};