class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num) return "";
        string s="";
        int mx=9;
        while(num>s.size()){
            mx=min(mx,sum);
            sum-=mx;
            s.push_back('0'+mx);
        }
        return s;
    }
};