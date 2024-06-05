// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n=nums.size();
//         int pre[n],suf[n];
//         pre[0]=1;
//         suf[n-1]=1;
//         for(int i=1;i<nums.size();i++){
//             pre[i]=pre[i-1]*nums[i-1];
//         }
//         for(int i=nums.size()-2;i>=0;i--){
//             suf[i]=suf[i+1]*nums[i+1];
//         }
//         for(int i=0;i<nums.size();i++){
//             nums[i]=pre[i]*suf[i];
//         }
//         return nums;
//     }
// };
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n);
        pre[0]=1;
        for(int i=1;i<nums.size();i++){
            pre[i]=pre[i-1]*nums[i-1];
        }
        int p=nums[n-1];
        for(int i=n-2;i>=0;i--){
            pre[i]*=p;
            p*=nums[i];
        }
        return pre;
    }
};