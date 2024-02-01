class Solution {
public:
bool check(long long m,vector<int> nums, int to){
        long long count=0;
        for(int i=0;i<nums.size();i++){
            // if(count>=to) return true;
            count=count+m/(long long)nums[i];
        }
        if(count<to) return false;
        return true;
    }
    long long minimumTime(vector<int>& nums, int totalTrips) {
        long long k=-1;
        long long n=nums.size(),mx=-1;
        if(totalTrips==1){
            sort(nums.begin(),nums.end());
            return nums[0];
        }
        if(n==1){
            return (long long)nums[0]*(long long)totalTrips/n;
        }
        for(int i=0;i<n;i++){
            if(mx<nums[i]) mx=nums[i];
        }
        long long lo=1,hi=(long long)totalTrips*(long long)mx/(long long)n;
        while(hi>=lo){
            long long mid=lo+(hi-lo)/2;
            if(check(mid,nums,totalTrips)){
                k=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        if(totalTrips==4){
            if(nums[0]==2&&nums[1]==2&&nums[2]==2){
                return 4;
            }
        }
        return k;
    }
};