class Solution {
public:
    int minimumSum(int num) {
        int ones=num%10;
        num/=10;
        int tens=num%10;
        num/=10;
        int huns=num%10;
        num/=10;
        int thou=num;
        vector<int>p;
        p.push_back(ones);
        p.push_back(tens);
        p.push_back(huns);
        p.push_back(thou);
        sort(p.begin(),p.end());
        int num1=p[0]*10+p[2];
        int num2=p[1]*10+p[3];
        return num1+num2;
    }
};