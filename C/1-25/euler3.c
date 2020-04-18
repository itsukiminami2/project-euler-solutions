#include <stdio.h>
#include <math.h>

long max_prime_factor(long n) {
    long max_prime = -1;
  
    while (n % 2 == 0) { 
        max_prime = 2;
        n = n >> 1;  // n = n / 2
    }

    double sqrt_n = sqrt(n);
    for (long i = 3; i <= sqrt_n; i += 2) { 
        while (n % i == 0) { 
            max_prime = i;
            n = n / i;
        }
    }
  
    if (n > 2) 
        max_prime = n;
  
    return max_prime;
}

int main() {
    long n = 600851475143;
    printf("%ld\n", max_prime_factor(n));

    return 0;
}