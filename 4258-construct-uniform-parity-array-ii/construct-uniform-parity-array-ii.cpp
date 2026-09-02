class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int e=0,o=0;
        for(int i:nums){
            e+=(i%2==0);
            o+=(i%2);
        }
        if(e==0) return 1;
        if(o==0) return 1;
        if((*min_element(begin(nums),end(nums)))%2) return 1;
        return 0;
    }
};