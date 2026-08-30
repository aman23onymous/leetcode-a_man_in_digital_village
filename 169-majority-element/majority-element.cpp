class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c=0,d=0;
        for(int x:nums){
            if(d==0)c=x;
            if(x==c) d++;
            else d--;
        }
        return c;
    }
};