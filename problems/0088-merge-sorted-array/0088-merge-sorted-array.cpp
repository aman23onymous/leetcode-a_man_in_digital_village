class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> k;
        for(int i=0;i<m;i++){
            k.push_back(nums1[i]);
        }
        int i=0,a=0,b=0;
        while(a<m&&b<n){
            if(k[a]<nums2[b]){
                nums1[i]=k[a];
                a++;
            }
            else{
                nums1[i]=nums2[b];
                b++;
            }
            i++;
        }
        if(a==m){
            while(b<n){
                nums1[i]=nums2[b];
                b++;
                i++;
            }
        }
        if(b==n){
            while(a<m){
                nums1[i]=k[a];
                a++;
                i++;
            }
        }
    }
};