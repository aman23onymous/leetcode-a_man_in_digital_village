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
            sort(begin(nums),end(nums));
            return;
        }
        // cout<<br;
        int k=br+1;
        for(int i=br+1;i<n;i++){
            if(nums[br]<nums[i]){
                if(nums[i]<nums[k]) k=i;
            }
        }
        cout<<k;
        swap(nums[k],nums[br]);
        sort(begin(nums)+br+1,end(nums));
    }
};