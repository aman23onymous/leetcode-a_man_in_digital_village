class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        vector<int> a(51,0);
        for(int i=0;i<nums.size();i++){
            a[nums[i]]++;
        }
        int i,k=0;
        for(i=1;i<=50;i++){
            cout<<" Ama ";
            if(a[i]==2){
                k=i++;
                break;
            }
        }
        cout<<i;
        for(;i<=50;i++){
            if(a[i]==2){
                k=k^i;
            }
        }
        return k;
    }
};