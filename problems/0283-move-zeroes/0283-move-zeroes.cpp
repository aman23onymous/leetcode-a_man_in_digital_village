class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size(),j=0,i=0;
        // for(int i=0;i<n-1;i++){
        //     if(nums[i]==0){
        //         for(j=i+1;j<n;j++){
        //             if(nums[j]!=0) break;
        //         }
        //         if(j<n)  swap(nums[i],nums[j]);
        //     }
        //     else i++;
        // }
        //I PE ZEROES AAYENGE J PE NON ZEROES
        while(i<n&&j<n){
            if(nums[i]==0&&nums[j]!=0){
                if(i<j) swap(nums[i],nums[j]);
                 else j++;
                 }
            else if(nums[i]!=0) i++;
            else if(nums[j]==0) j++;
        }
    }
};