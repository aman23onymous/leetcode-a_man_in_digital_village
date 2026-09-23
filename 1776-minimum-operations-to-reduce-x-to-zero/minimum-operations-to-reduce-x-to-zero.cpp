class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int s=0,mx=0;
        x=accumulate(begin(nums),end(nums),0)-x;
        if(x==0) return nums.size();
        for(int i=0,j=0;i<nums.size();i++){
            s+=nums[i];
            while(j<=i and s>x){
                s-=nums[j];
                j++;
            }
            if(s==x) mx=max(mx,i-j+1);
        }
        if(mx==0) return -1;
        return nums.size()-mx;
    }
};