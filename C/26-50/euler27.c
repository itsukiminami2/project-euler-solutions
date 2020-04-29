#include <stdio.h>

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

int main() {
    int max_n = 0, max_a, max_b;

    for(int a = -999; a <= 999; ++a) {
        for(int b = -1000; b <= 1000; ++b) {
            int n = 0;
            while(is_prime(n*n + a*n + b)) {
                ++n;
            }

            if(n > max_n) {
                max_n = n;
                max_a = a;
                max_b = b;
            }
        }
    }

    printf("%d\n", max_a*max_b);

    return 0;
}