class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        if(k==1) return 1;
        map<int,int>mp;
        int cr=-nums[0],n=nums.size();
        mp[k-1]=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]+cr==0){
                if(mp.count(i)) cr+=mp[i];
            }
            else if(nums[i]+cr>0){
                int ext=nums[i]+cr;
                if(i+k-1>=n) return 0;
                mp[i+k-1]=ext;
                cr=-nums[i];
                if(mp.count(i)) cr+=mp[i];
            }
            else return 0;
        }
        return 1;
    }
};