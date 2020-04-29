#include <stdio.h>
#include <math.h>

// returns 0 if 'n' is not prime, 1 otherwise.
int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }

    for(int i = 2; i*i <= n; ++i) {
        if(n % i == 0) {
            return 0;
        }
    }

    return 1;
}

/*
    circular_prime(n) - returns 1 if 'n' and all its rotations are prime, i.e., 'n' is a circular prime,
                        0 otherwise.
*/
int circular_prime(int n) {
    if(!is_prime(n)) {
        return 0;
    }

    int digits = floor(log10(n)) + 1;  // number of digits in 'n'
    for(int i = 1; i < digits; ++i) {
        int rem = n % 10;
        int quotient = n / 10;

        int next = (rem * pow(10, digits-1) + quotient); // next rotation -> (remainder * 10^(digits-1) + quotient)
        
        if(!is_prime(next)) {
            return 0;
        }
        
        n = next;
    }

    return 1;
}

int main() {
    int n = 2, count = 0;
    while(n < 1000000) {
        if(circular_prime(n)) {
            count++;
        }

        n++;
    }
    
    printf("%d\n", count);

    return 0;
}