class Solution {
public:
    int specialArray(vector<int> &nums){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    if(n<=nums[0]) return n;
    for(int i=0;i<n;i++){
        int len=n-i;
       // if(nums[i]==nums[i-1]) continue;
        if(len<=nums[i]&&len>nums[i-1]) return len;
    }
    return -1;
}
};