class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> p;

        for(int i = left; i <= right; i++) {
            int x = i;
            bool f = true;

            // Check each digit of the number
            while(x != 0) {
                int digit = x % 10;
                
                // If the digit is 0 or the number is not divisible by this digit
                if (digit == 0 || i % digit != 0) {
                    f = false;
                    break;
                }
                x /= 10;
            }

            if(f) p.push_back(i);
        }

        return p;
    }
};