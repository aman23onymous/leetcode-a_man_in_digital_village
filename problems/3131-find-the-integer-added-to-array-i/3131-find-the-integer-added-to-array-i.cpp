class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int mbx=-1,mx=-1;
        for(int i=0;i<nums1.size();i++){
            mbx=max(mbx,nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            mx=max(mx,nums2[i]);
        }
        return mx-mbx;
    }
};