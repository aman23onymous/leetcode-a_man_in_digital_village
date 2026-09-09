class Solution {
public:
    long long countCommas(long long n) {
        return (n > 999) * (n - 999)+(n > 999999) * (n - 999999)+(n > 999999999) * (n - 999999999)+(n > 999999999999) * (n - 999999999999)+(n > 999999999999999) * (n - 999999999999999);;
    }
};