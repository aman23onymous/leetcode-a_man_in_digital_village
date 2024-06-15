class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        vector<int> x(10,0);
        int a=10,b=10;
        for(int i=0;i<nums1.size();i++) x[nums1[i]-1]++,a=min(a,nums1[i]);
        for(int j=0;j<nums2.size();j++) x[nums2[j]-1]++,b=min(b,nums2[j]);
        // if(a==b) return a;
        for(int i=0;i<10;i++) if(x[i]==2) return i+1;
        if(a<b) return 10*a+b;
        return 10*b+a;
    }
};