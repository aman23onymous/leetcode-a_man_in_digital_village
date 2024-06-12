class Solution {
public:
    int set(int n){
        int a=0;
        while(n>0){
            if(n&1) a++;
            n=n>>1;
        }
        return a;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int s=0;
        for(int i=0;i<nums.size();i++){
            if(set(i)==k) s+=nums[i];
        }
        return s;
    }
};