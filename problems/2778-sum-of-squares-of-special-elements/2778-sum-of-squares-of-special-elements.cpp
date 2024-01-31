class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sum=0,n=nums.size(),i=0;
        while(i<n){
            if(n%(i+1)==0){
                sum=sum+nums[i]*nums[i];
            }
            i++;
        }
        return sum;
    }
};