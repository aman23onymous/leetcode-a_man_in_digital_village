class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int p=nums.size(),sum1=0,sum2=0;
        for(int i=1;i<p;i++){
            sum1+=nums[i];
        }
        int k=sum1;
        for(int i=1;i<p;i++){
            if(sum1==sum2) return i-1;
            sum2+=nums[i-1];
            sum1-=nums[i];
        }
        if(k+nums[0]==0&&nums[p-1]==0) return p-1;
        if(sum2==0) return p-1;
        return -1;
    }
};