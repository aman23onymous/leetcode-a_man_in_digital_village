class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int mxln=INT_MIN,ln,i=0,j=0,n=nums.size(),flips=0;
        while(j<n){
            if(nums[j]==0){
                if(flips<k) flips++,j++;
                else {
                    ln=j-i;
                    mxln=max(ln,mxln);
                    j=++i;
                    flips=0;
                }
            }
            else j++;
        }
        // if(flips<=k&&mxln==INT_MIN) return n;
        ln=j-i;
        mxln=max(ln,mxln);
        return mxln;
    }
};