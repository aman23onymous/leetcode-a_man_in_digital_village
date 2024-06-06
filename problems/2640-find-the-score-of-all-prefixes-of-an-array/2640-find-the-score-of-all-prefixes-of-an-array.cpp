class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n=nums.size();
        vector<long long> fi(n);
        fi[0]=nums[0];
        for(int i=1;i<n;i++){
            if(fi[i-1]>nums[i]) fi[i]=fi[i-1];
            else fi[i]=nums[i];
        }    
        for(int i=0;i<n;i++){
            fi[i]+=nums[i];
        }
        for(int i=1;i<n;i++){
            fi[i]+=fi[i-1];
        }
        return fi;
    }
};