class Solution {
public:
    #include <vector>
#include <cmath>

int countPrimes(int n) {
    if (n <= 2) return 0;
    
    vector<bool> isPrime(n, true);
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers

    int limit = std::sqrt(n); // Calculate the square root of n

    for (int i = 2; i <= limit; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int primeCount = 0;
    for (int i = 2; i < n; ++i) {
        if (isPrime[i]) {
            primeCount++;
        }
    }

    return primeCount;
}

};