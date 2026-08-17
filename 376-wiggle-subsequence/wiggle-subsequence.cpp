class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        int k=0;
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            while(j<nums.size()){
                if(k%2 and nums[j-1]<nums[j])break;
                else if(k%2==0 and nums[j-1]>nums[j]) break;
                j++;
            }
            k++;
            i=j-1;
        }
        int l=0;
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            while(j<nums.size()){
                if(l%2 and nums[j-1]>nums[j])break;
                else if(l%2==0 and nums[j-1]<nums[j]) break;
                j++;
            }
            l++;
            i=j-1;
        }
        return max(k,l);
    }
};