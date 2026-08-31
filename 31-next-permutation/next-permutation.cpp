class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),br=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                br=i;
                break;
            }
        }
        if(br==-1){
            reverse(begin(nums),end(nums));
            return;
        }
        // cout<<br;
        int k=br+1;
        for(int i=n-1;i>br;i--){
            if(nums[br]<nums[i]){
                k=i;
                break;
            }
        }
        swap(nums[k],nums[br]);
        reverse(begin(nums)+br+1,end(nums));
    }
};