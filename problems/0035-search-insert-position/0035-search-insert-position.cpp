class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1,mid;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]>=target) j=mid-1;
            else i=mid+1;
        }
        return j+1;
    }
};