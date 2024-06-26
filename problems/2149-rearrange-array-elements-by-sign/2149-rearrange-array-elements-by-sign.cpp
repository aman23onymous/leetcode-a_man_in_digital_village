class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> n(nums.size()/2,9),p(nums.size()/2);
        for(int i=0,j=0,k=0;i<nums.size();i++){
            if(nums[i]>0) p[j++]=nums[i];
            else n[k++]=nums[i];
        }
        for(int i=0;i<nums.size();i+=2) nums[i]=p[i/2],nums[i+1]=n[i/2];
        return nums;
    }
};