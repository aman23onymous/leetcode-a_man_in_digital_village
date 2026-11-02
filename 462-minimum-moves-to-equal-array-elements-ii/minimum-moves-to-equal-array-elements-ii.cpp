class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size(),ns=0;
        if(n%2){
            for(int i=0;i<n;i++){
                ns+=abs(nums[i]-nums[n/2]);
            }
        }
        else {
            for(int i=0;i<n;i++){
                ns+=abs(nums[i]-nums[n/2]);
            }
        }
        return ns;
    }
};