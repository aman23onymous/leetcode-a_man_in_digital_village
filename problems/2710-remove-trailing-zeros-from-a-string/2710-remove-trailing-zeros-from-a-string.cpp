class Solution {
public:
    string removeTrailingZeros(string num) {
        reverse(num.begin(),num.end());
        int c=0;
        while(num[c]=='0'){
            c++;
        }
        reverse(num.begin(),num.end());
        while(c!=0){
            num.pop_back();
            c--;
        }
        return num;
    }
};