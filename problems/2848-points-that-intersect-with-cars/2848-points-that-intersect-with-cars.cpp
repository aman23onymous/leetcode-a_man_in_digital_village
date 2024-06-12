class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<bool> d(100,false);
        for(int i=0;i<nums.size();i++){
            for(int j=nums[i][0];j<=nums[i][1];j++){
                d[j-1]=true;
            }
        }
        int k=0;
        for(int i=0;i<100;i++){
            if(d[i]) k++;
        }
        return k;
    }
};