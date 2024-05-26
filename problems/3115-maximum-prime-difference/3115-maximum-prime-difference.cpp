class Solution {
public:
    bool prime(int n){
        if(n==1) return false;
        for(int i=2;i<=n/2;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        vector<int> f;
        int min=nums.size(),max=-1;
        for(int i=0;i<min;i++){
            if(prime(nums[i])) f.push_back(i);
        }
        for(int i=0;i<f.size();i++){
            if(min>f[i]) min=f[i];
            if(max<f[i]) max=f[i];
        }
        return max-min;
    }
};