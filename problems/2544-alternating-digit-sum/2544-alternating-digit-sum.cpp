class Solution {
public:
int alternateDigitSum(int n) {
        int a = 0, x = 0, b = n;
            
                while (b > 0) { b /= 10; x++; }
                    
                        b = n;
                            
                                if (x % 2) {
                                        while (b > 0) { a += (b % 10); b /= 100; }
                                                n /= 10;
                                                        while (n > 0) { a -= (n % 10); n /= 100; }
                                                            } else {
                                                                    while (b > 0) { a -= (b % 10); b /= 100; }
                                                                            n /= 10;
                                                                                    while (n > 0) { a += (n % 10); n /= 100; }
                                                                                        }
                                                                                            
                                                                                                return a;
                                                                                                }
                                                                                                

       

};